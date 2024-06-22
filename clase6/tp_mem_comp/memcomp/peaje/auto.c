#include "stdio.h"
#include "stdlib.h"
#include "global.h"
#include "memcomp.h"
#include "funciones.h"
#include "auto.h"
#include "semaforo.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "unistd.h"


int main (int argc, char const *argv[])
{
	int cantViasParams = 0,cantVias = 0,id_memoria = 0,id_semaforo = 0,locationMin = 0;
	struct peaje *stPeaje; /*No lleva malloc pq le da el size en creo memoria*/
	id_semaforo = creo_semaforo();

	if (argc == 2){
		cantViasParams = atoi(argv[1]);
	}else{
		printf("Ingrese cantidad de vias: \n");
		scanf("%d", &cantVias);
	}
	stPeaje = (peaje*)creo_memoria(sizeof(peaje)*cantVias,&id_memoria);
	while (1){

		espera_semaforo(id_semaforo);
		locationMin = getlocationmin(stPeaje,cantVias);
		printf("Se agrega un auto a la via %d\n",locationMin);
		stPeaje[locationMin].autos += 1;
		levanta_semaforo(id_semaforo);
		usleep(createrandomparams(1000000,2000000));

	}
	shmdt((char *)stPeaje);
	shmctl(id_memoria,IPC_RMID,(struct shmid_ds *)NULL);
	return 0;	
}

int getlocationmin(struct peaje *stPeaje, int cantVias)
{
	int i = 0, location = 0;
	for ( i = 0 ; i < cantVias; i++)
	{
		if (stPeaje[i].autos < stPeaje[location].autos)
		{
			location = i;
		}
	}
	return location;
}
