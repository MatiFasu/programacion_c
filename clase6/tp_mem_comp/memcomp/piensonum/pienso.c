#include "stdio.h"
#include "stdlib.h"
#include "sys/shm.h"
#include "sys/ipc.h"
#include "unistd.h"
#include "global.h"
#include "memcomp.h"
#include "funciones.h"
#include "pienso.h"
#include "semaforo.h"
#include "time.h"

int main (int argc, char const *argv[])
{
	int local_pienso_num = 0,id_memoria = 0,id_semaforo = 0, ganador = FALSE;
		
	struct juego *stJuego; /*No lleva malloc pq le da el size en creo memoria*/
	srand(time(NULL));
	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo , VERDE);
	stJuego = (juego*)creo_memoria(sizeof(juego),&id_memoria);
	local_pienso_num = createrandomparams(1,99);

	while(ganador != TRUE){
		espera_semaforo(id_semaforo);
		if (stJuego[0].numero_pensado != 0)
		{
			if (local_pienso_num == stJuego[0].numero_pensado)
			{
				ganador = TRUE;
				stJuego[0].estado_acierto = 1;
				printf("%s Adivino el numero %d \n", stJuego[0].nombre_jugador,stJuego[0].numero_pensado);
			}else
		printf("nombre jugador: %s, numero pensado: %d ,  estado acierto: %d , wining:%d \n", stJuego[0].nombre_jugador,stJuego[0].numero_pensado,stJuego[0].estado_acierto,local_pienso_num); 
				stJuego[0].numero_pensado = 0;
		}
usleep(2000);
		levanta_semaforo(id_semaforo);
	
	}

	shmdt((char *)stJuego);
	shmctl(id_memoria,IPC_RMID,(struct shmid_ds *)NULL);
	return 0;
}
