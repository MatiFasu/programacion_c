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
	int i, posicion;
	int id_semaforo;
	int cajero;

	srand(time(NULL));

	id_semaforo = creo_semaforo();

	inicia_semaforo(id_semaforo, ROJO);

	memoria = (dato*)creo_memoria(sizeof(dato)*CANT, &id_memoria);

	cajero = atoi(argv[1]);

	printf("CAJERO %d \n", cajero);

	while(1)
	{
		espera_semaforo(id_semaforo);		

			posicion = -1;
			i=0;
			while(posicion == -1 && i < 100)
			{
				if(memoria[i].listo == 0) {
					posicion = i;
					memoria[i].cajero = cajero;
					memoria[i].importe  = devolverAleatorio(100, 1000);
					memoria[i].cheque = devolverAleatorio(0,1);
					memoria[i].listo = 1;
					printf("Escrito %d %d %d %d\n", memoria[i].cajero, memoria[i].importe, memoria[i].cheque, memoria[i].listo);
					sleep (1);
				}
				
				i++;
			}

		levanta_semaforo(id_semaforo);
		sleep (10);
		printf("\n");
	}

	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);

	printf("\n");
	return 0;
}
