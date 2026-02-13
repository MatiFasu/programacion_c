#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <pthread.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <def.h>
#include <archivos.h>
#include <global.h>
#include <clave.h>
#include <semaforo.h>
#include <memoria.h>
#include <cola.h>

/*PISTA*/

int main(int argc, char* argv[]) {
	
	int id_cola_mensajes;
	int i, pasos, done=1;
	Hormiga corredores[CANTIDAD_HORMIGAS];
	int* memoria = NULL;
	int id_memoria, id_semaforo;
	char nombre_hormiga[50];
	int id_ganador=0, cantidad_empate=0;
	mensaje msg;

	id_cola_mensajes = creo_id_cola_mensajes();
	id_semaforo = creo_semaforo();
	memoria = (int*) creo_memoria(sizeof(int), &id_memoria, CLAVE_BASE);

	*memoria += 1;
	printf("Esperando que todos los procesos esten corriendo...\n");

	if(*memoria==1) {
		espera_semaforo(id_semaforo);
	} else {
		levanta_semaforo(id_semaforo);
	}
	
	while(done) {
		
		recibir_mensaje(id_cola_mensajes, MSG_PISTA, &msg);

		switch(msg.int_evento) {
			
			case EVT_CORRO:
				sscanf(msg.char_mensaje, "%[^-]-%d", nombre_hormiga, &pasos);
				printf("\nLa hormiga %s a avanzado %d pasos!\n", nombre_hormiga, pasos);
				break;
			case EVT_FIN:
				sscanf(msg.char_mensaje, "%[^-]-%d", nombre_hormiga, &pasos);
				printf("\nLa hormiga %s ha llegado a la meta en %d pasos!\n", nombre_hormiga, pasos);
				strcpy(corredores[done].nombre, nombre_hormiga);
				corredores[done].cantidad_pasos = pasos;
				done = 0;
				break;
			default:
				printf("Hormiga %s: evento sin definir\n", nombre_hormiga);
				break;
		}
	
		sleep(1);

	};

	for(i=0; i<CANTIDAD_HORMIGAS; i++) {
		
		if(corredores[i].cantidad_pasos < corredores[id_ganador].cantidad_pasos) {
			id_ganador = i;
		} else if(corredores[i].cantidad_pasos == corredores[id_ganador].cantidad_pasos) {
			cantidad_empate++;
		} 

	}

	if(cantidad_empate != CANTIDAD_HORMIGAS) {
		printf("El ganador de la carrera fue %s con %d pasos !!!", corredores[id_ganador].nombre, corredores[id_ganador].cantidad_pasos);
	} else {
		printf("Triple empate!!!");
	}


	liberar_memoria((char*)memoria, id_memoria);

	printf("\n");
	return 0;
}
