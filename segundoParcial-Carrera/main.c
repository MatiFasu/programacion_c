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

/*TABLERO*/

int main(int argc, char* argv[]) {
	
	int id_cola_mensajes;
	int i, pasos, done=0;
	Animal corredores[CANTIDAD_ANIMALES];
	int* memoria = NULL;
	int id_memoria, id_semaforo;
	char nombre_animal[50];
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
	
	while(done<CANTIDAD_ANIMALES) {
		
		recibir_mensaje(id_cola_mensajes, MSG_TABLERO, &msg);

		switch(msg.int_evento) {
			
			case EVT_CORRO:
				sscanf(msg.char_mensaje, "%[^-]-%d", nombre_animal, &pasos);
				printf("\nEl %s a avanzado %d pasos!\n", nombre_animal, pasos);
				break;
			case EVT_FIN:
				sscanf(msg.char_mensaje, "%[^-]-%d", nombre_animal, &pasos);
				printf("\nEl %s ha llegado a la meta en %d pasos!\n", nombre_animal, pasos);
				strcpy(corredores[done].nombre, nombre_animal);
				corredores[done].cantidad_pasos = pasos;
				done += 1;
				break;
			default:
				printf("Animal %s: evento sin definir\n", nombre_animal);
				break;


		}
	
	};

	for(i=1; i<CANTIDAD_ANIMALES; i++) {
		
		if(corredores[i].cantidad_pasos < corredores[id_ganador].cantidad_pasos) {
			id_ganador = i;
		} else if(corredores[i].cantidad_pasos == corredores[id_ganador].cantidad_pasos) {
			cantidad_empate++;
		} 

	}

	if(cantidad_empate != CANTIDAD_ANIMALES) {
		printf("El ganador de la carrera fue %s con %d pasos !!!", corredores[id_ganador].nombre, corredores[id_ganador].cantidad_pasos);
	} else {
		printf("Triple empate!!!");
	}


	liberar_memoria((char*)memoria, id_memoria);

	printf("\n");
	return 0;
}
