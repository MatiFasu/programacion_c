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
#include <jugadorThread.h>

/*JUGADOR*/

int main(int argc, char* argv[]) {

	int id_cola_mensajes;
	int i, ctl=0;
	int cant_jugadores;
	
	tJugador *datos_thread;

	pthread_t* idHilo;
	pthread_attr_t atributos;	
	
	printf("Ingrese cantidad de jugadores: ");
	scanf("%d", &cant_jugadores);

	idHilo = (pthread_t*) malloc(sizeof(pthread_t)*cant_jugadores);

	id_cola_mensajes = creo_id_cola_mensajes();

	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

	datos_thread = (tJugador*)malloc(sizeof(tJugador)*cant_jugadores);

	srand(time(NULL));

	for(i=0; i<cant_jugadores; i++) {
		datos_thread[i].nro_jugador = i;
		datos_thread[i].id_cola_msg = id_cola_mensajes;
		datos_thread[i].cant_jugadores = cant_jugadores;

		pthread_create(&idHilo[i], &atributos, jugadorThread, &datos_thread[i]);
	}

	for(i=0; i<cant_jugadores; i++) {
		pthread_join(idHilo[i], NULL);
		printf("Finalizo el jugador %d \n", datos_thread[i].nro_jugador);
	}

	/*free(idHilo);*/

	printf("\n");
	return 0;
}
