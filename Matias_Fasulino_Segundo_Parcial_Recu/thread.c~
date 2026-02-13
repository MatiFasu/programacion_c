#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <global.h>
#include <animalThread.h>
#include <def.h>
#include <cola.h>

pthread_mutex_t mutex;

void* threadAnimal(void* parametro)
{
		
	int id_animal;
	int id_cola_mensajes;
	char nombre_animal[50], cadena[50];
	int pasos=0, pasos_totales=0;

	Animal *datos_animal = (Animal*) parametro;
	sprintf(nombre_animal, "%s", datos_animal->nombre); /*nombre_animal*/
	id_animal = datos_animal -> id_animal;
	id_cola_mensajes = datos_animal -> id_cola_msg;

	printf("Soy el %s\n", nombre_animal);

	while(pasos_totales < META) {
		printf("\nBloquear\n");
		pthread_mutex_lock(&mutex);

		pasos = devolverAleatorio(datos_animal->velocidad_min, datos_animal->velocidad_max);
		printf("El %s dio %d pasos", nombre_animal, pasos);
		sprintf(cadena, "%s-%d", nombre_animal, pasos);
		pasos_totales += pasos;
		enviar_mensaje(id_cola_mensajes, MSG_TABLERO, MSG_ANIMAL+datos_animal->id_animal, EVT_CORRO, cadena);
		datos_animal->cantidad_pasos += 1;		

		pthread_mutex_unlock(&mutex);
		printf("\nDesbloquear\n");
		sleep(1);		
	};


	pthread_exit((void*)"Listo");
}

