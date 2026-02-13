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
#include <animalThread.h>

/*ANIMAL*/

int main(int argc, char* argv[]) {

	int id_cola_mensaje;
	int i;
	int cantidad=CANTIDAD_ANIMALES;
	int *memoria = NULL;
	int id_memoria, id_semaforo;
	char cadena[50];

	Animal *datos_animal;
	pthread_t* idHilo;
	pthread_attr_t atributos;
	
	memset(cadena, 0x00, sizeof(cadena));
	srand(time(NULL));

	id_semaforo = creo_semaforo();
	memoria = (int*) creo_memoria(sizeof(int), &id_memoria, CLAVE_BASE);

	*memoria += 1;
	printf("Esperando que todos los procesos esten corriendo...\n");

	if(*memoria == 1) {
		printf("Esperando que todos los procesos esten corriendo...\n");
		espera_semaforo(id_semaforo);
	} else {
		printf("Arranca la carrera\n");
		levanta_semaforo(id_semaforo);
	}

	id_cola_mensaje = creo_id_cola_mensajes();
	borrar_mensajes(id_cola_mensaje);

	idHilo = (pthread_t*)malloc(sizeof(pthread_t)*cantidad);
	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

	datos_animal = (Animal*)malloc(sizeof(Animal)*cantidad);
	
		/* Lanzo Conejo */
		datos_animal[0].id_animal = 0;
		strcpy(datos_animal[0].nombre, "Conejo");
		datos_animal[0].id_cola_msg = id_cola_mensaje;
		datos_animal[0].velocidad_min = CNJ_VEL_MIN;
		datos_animal[0].velocidad_max = CNJ_VEL_MAX;
		pthread_create(&idHilo[0], &atributos, threadAnimal, &datos_animal[0]);
		/* Lanzo Gato */
		datos_animal[1].id_animal = 1;
		strcpy(datos_animal[1].nombre, "Gato");
		datos_animal[1].id_cola_msg = id_cola_mensaje;
		datos_animal[1].velocidad_min = GATO_VEL_MIN;
		datos_animal[1].velocidad_max = GATO_VEL_MAX;
		pthread_create(&idHilo[0], &atributos, threadAnimal, &datos_animal[1]);
		/* Lanzo Perro */
		datos_animal[2].id_animal = 2;
		strcpy(datos_animal[2].nombre, "Perro");
		datos_animal[2].id_cola_msg = id_cola_mensaje;
		datos_animal[2].velocidad_min = PERRO_VEL_MIN;
		datos_animal[2].velocidad_max = PERRO_VEL_MAX;
		pthread_create(&idHilo[2], &atributos, threadAnimal, &datos_animal[2]);

	for(i=0; i<cantidad; i++) {
		pthread_join(idHilo[i], NULL);
		printf("%s llego a la meta.\n", datos_animal[i].nombre);
		sprintf(cadena, "%s-%d", datos_animal[i].nombre, datos_animal[i].cantidad_pasos);
		enviar_mensaje(id_cola_mensaje, MSG_TABLERO, MSG_TABLERO, EVT_FIN, cadena);
	}	


	liberar_memoria((char*)memoria, id_memoria);
	
	printf("\n");
	return 0;
}
