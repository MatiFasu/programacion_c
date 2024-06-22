#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <def.h>
#include <archivos.h>
#include <global.h>
#include <clave.h>
#include <semaforo.h>



int main(int argc, char* argv[]) {
	
	int id_semaforo = 0;	
	
	id_semaforo =  creo_semaforo();

	inicia_semaforo(id_semaforo, VERDE);
	
	printf("%d\n", id_semaforo);

	while(1) 
	{
		espera_semaforo(id_semaforo);
			printf("Seccion Critica\n");
			sleep(1);
		levanta_semaforo(id_semaforo);			
		sleep(3);

	}



	printf("\n");
	return 0;
}
