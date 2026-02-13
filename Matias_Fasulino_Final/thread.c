#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <global.h>
#include <thread.h>
#include <def.h>
#include <cola.h>

pthread_mutex_t mutex;

void* funcionThread(void* parametro)
{	
	int id_cola_mensajes;
	int id_pais;
	int done=1;
	char cadena[50];
	int disparo;
	char nombre[20];
	int barcos_vivos;
	int id_pais_enemigo;
	int i;
	int cantidad_jugadores;
	
	Pais *datos_pais = (Pais*) parametro;
	id_pais = datos_pais->id_pais;
	strcpy(nombre, datos_pais->nombre);
	id_cola_mensajes = datos_pais->id_cola_msg;
	barcos_vivos = datos_pais->barcos_vivos;
	cantidad_jugadores = CANTIDAD_PAISES;

	
	while(done) {
		printf("\nBloquear\n");
		pthread_mutex_lock(&mutex);
		
		if( datos_pais->barcos_vivos != 0 ) {

			do {
				id_pais_enemigo = devolverAleatorio(0,cantidad_jugadores-1);
			} while (id_pais_enemigo == id_pais);		

			disparo = devolverAleatorio(1, 5);

			printf("Soy el Pais %d (%s) - Ataco a: %d con disparo: %d \n", id_pais, datos_pais->nombre, id_pais_enemigo, disparo);

			sprintf(cadena, "%d-%d-%d-%s", id_pais, disparo, id_pais_enemigo, nombre);
			if( datos_pais->barcos_vivos>0 ) {
				enviar_mensaje(id_cola_mensajes, MSG_TABLERO, MSG_PAIS+datos_pais->id_pais, EVT_DISPARAR, cadena);
			}
				
		} else {
			printf("Se ha llamado a un jugador eliminado");
			enviar_mensaje(id_cola_mensajes, MSG_TABLERO, MSG_PAIS+datos_pais->id_pais, EVT_FIN, cadena);
		}

		pthread_mutex_unlock(&mutex);
		printf("\nDesbloquear\n");
		sleep(20);		
	};
	


	pthread_exit((void*)"Listo");
}

