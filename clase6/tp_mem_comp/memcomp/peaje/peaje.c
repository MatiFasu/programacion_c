#include "stdio.h"
#include "stdlib.h"
#include "global.h"
#include "memcomp.h"
#include "funciones.h"
#include "peaje.h"
#include "semaforo.h"
#include "sys/ipc.h"
#include "gestorArchivos.h"
#include "unistd.h"
#include "sys/shm.h"

int main (int argc, char *argv[])
{
	int  cantViasParams = 0, id_memoria = 0,id_semaforo = 0, i = 0, cantVias = 0,temp = 0,contliberacion = 0;
	struct peaje *stPeaje; /*No lleva malloc pq le da el size en creo memoria*/
	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo , VERDE);
	if (argc == 2){
		cantViasParams = atoi(argv[1]);
	}else{
		printf("Ingrese cantidad de vias: \n");
		scanf("%d", &cantVias);
	}

	printf("cantVias  %d\n",cantVias);
	stPeaje = (peaje*)creo_memoria(sizeof(peaje)*cantVias,&id_memoria);

	while (1)
	{
		espera_semaforo(id_semaforo);
		if (temp >= cantVias){
			temp = 0;
		}
		for (i=0 ; i<cantVias ; i++)
		{
			stPeaje[i].numPeaje = i;
			printf ("VIA[%d]:  %d vehiculos\n", i, stPeaje[i].autos);
			
			if(stPeaje[i].autos >= 10)
			{
				stPeaje[i].autos = 0;
				printf("Se libero el carril por tener 10 autos o mas\n");
				contliberacion += 1;
			}
		}
		
		if (stPeaje[temp].autos >= 1){
			stPeaje[temp].autos -= 1;
			printf("Se resto un auto de %d nuevacant %d\n",temp,stPeaje[temp].autos);
		}
		temp += 1;
		
		
		printf ("Se van liberando %d carriles\n", contliberacion);
		if (openfileclean("liberaciones.txt") ==  TRUE)
		{
			fprintf(archivo,"%d", contliberacion);
			fclose(archivo);
		}
		
		levanta_semaforo(id_semaforo);
		usleep(createrandomparams(4000000,6000000));
		
	
	}
	shmdt((char *)stPeaje);
	shmctl(id_memoria,IPC_RMID,(struct shmid_ds *)NULL);
	return 0;
}


