#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <def.h>
#include <archivos.h>
#include <global.h>
#include <clave.h>
#include <semaforo.h>
#include <memoria.h>

/*
los dos procesos no empiezen hasta que los dos procesos no esten corriendo
*/

int main(int argc, char* argv[]) {
	
	dato *memoria = NULL;
	int id_memoria;
	int i, aleatorio;
	int id_semaforo;

	srand(time(NULL));

	id_semaforo = creo_semaforo();
	
	inicia_semaforo(id_semaforo, VERDE);

	memoria = (dato*)creo_memoria(sizeof(dato)*CANT, &id_memoria, CLAVE_BASE);

	while(CANT_TOTAL)
	{
		espera_semaforo(id_semaforo);		
			printf("Escribimos en la memoria\n");
			for (i=0; i<CANTIDAD; i++)
			{
				aleatorio = rand()%(HASTA-DESDE)+DESDE;
				memoria[i].numero = aleatorio ;
				memoria[i].letra  = 0x41 + aleatorio ;
				printf("Escrito %d %c\n", memoria[i].numero, memoria[i].letra);
				sleep (1);
			}
			printf("Dejamos de escribir en la memoria\n");
		levanta_semaforo(id_semaforo);
		sleep (5);
	}

	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);

	printf("\n");
	return 0;
}
