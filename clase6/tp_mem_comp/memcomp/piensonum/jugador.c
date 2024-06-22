#include "sys/shm.h"
#include "sys/ipc.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "global.h"
#include "memcomp.h"
#include "funciones.h"
#include "jugador.h"
#include "semaforo.h"
#include "string.h"
#include "time.h"


int main (int argc, char const *argv[])
{
	int cont = 0,temp = 0,id_memoria = 0,id_semaforo = 0, l_num_pensado = 0;
	char nombre_jugador[LARGO_CADENA];
	struct juego *stJuego; /*No lleva malloc pq le da el size en creo memoria*/
	memset(nombre_jugador, 0x00, sizeof(nombre_jugador)*LARGO_CADENA);
	srand(time(NULL));
	id_semaforo = creo_semaforo();
	stJuego = (juego*)creo_memoria(sizeof(juego),&id_memoria);
	printf("Ingrese el nombre de jugador: \n");
	scanf("%s", nombre_jugador);
	strcpy(stJuego[0].nombre_jugador,nombre_jugador);
	l_num_pensado = createrandomparams(1,100);
	while (!hayGanador(stJuego[0]))
	{ 
		espera_semaforo(id_semaforo);
		if(stJuego[0].numero_pensado == 0)
		{
			while (l_num_pensado == temp)
			{
				l_num_pensado = createrandomparams(1,100);
			}
			stJuego[0].numero_pensado = l_num_pensado;
			printf("nombre jugador: %s, numero pensado: %d ,  estado acierto: %d , temp: %d \n", stJuego[0].nombre_jugador,stJuego[0].numero_pensado,stJuego[0].estado_acierto,temp);
		}
		cont +=1;
		temp = l_num_pensado;
		levanta_semaforo(id_semaforo);
		usleep(500000);
	}
	printf("\n%s acerto con %d intentos\n",nombre_jugador,cont);
	shmdt((char *)stJuego);
	shmctl(id_memoria,IPC_RMID,(struct shmid_ds *)NULL);
	return 0;
}



