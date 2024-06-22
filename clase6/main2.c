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



int main(int argc, char* argv[]) {

	dato *memoria = NULL;
	int id_memoria;
	int i;
	int id_semaforo;

	id_semaforo = creo_semaforo();

	memoria = (dato*)creo_memoria(sizeof(dato)*CANTIDAD, &id_memoria, CLAVE_BASE);
	
	while(1)
	{
		espera_semaforo(id_semaforo);			
			printf("leemos la memoria\n");
			for (i=0; i<CANTIDAD; i++)
			{
					printf("Leido %d %c\n", memoria[i].numero, memoria[i].letra);
			}
			printf("Dejamos de leer la memoria\n");
		levanta_semaforo(id_semaforo);
		sleep(5);
	}


	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);

	printf("\n");
	return 0;
}
