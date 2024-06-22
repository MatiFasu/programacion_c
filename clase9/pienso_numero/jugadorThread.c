#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <global.h>
#include <jugadorThread.h>
#include <def.h>
#include <cola.h>
#include<funciones.h>

pthread_mutex_t mutex;

void* jugadorThread(void* parametro)
{
	int nro_jugador;
	int id_cola_mensajes;
	int done=0;
	int cant_jugadores;
	int numero;
	int cant_intentos=0, i;
	char cadena[50];
	mensaje msg;

	tJugador* datos_thread = (tJugador*) parametro;
	nro_jugador = datos_thread->nro_jugador;
	id_cola_mensajes = datos_thread->id_cola_msg;
	cant_jugadores = datos_thread->cant_jugadores;

	srand(time(NULL));

	while(done==0) {

		numero = devolverAleatorio(1,10);	

		printf("\nJugador: %d, envia el numero: %d", nro_jugador, numero);
		sprintf(cadena, "%d", numero);
		enviar_mensaje(id_cola_mensajes, MSG_PIENSO, MSG_JUGADOR+nro_jugador, EVT_NUMERO, cadena);
		cant_intentos++;
		recibir_mensaje(id_cola_mensajes, MSG_JUGADOR, &msg);
		
		switch(msg.int_evento)
		{
			case EVT_ACERTO:
				printf("\nACerte! Con: %d cantidad de intentos \n", cant_intentos);
				for(i=0; i<cant_jugadores; i++) {
					enviar_mensaje(id_cola_mensajes, MSG_JUGADOR+i, MSG_JUGADOR+nro_jugador, EVT_FINALIZAR, "FINALIZAR");
				}
				break;
			case EVT_NO_ACERTO:
				printf("\nJugador: %d, siga intentando! \n", nro_jugador);
				break;
			case EVT_FINALIZAR:
				printf("\nJugador: %d Finalizo y gano el jugador: %d\n", nro_jugador, msg.int_rte-MSG_JUGADOR);
				done=1;
				break;
			default:
				break;
		}
	
		sleep(2);
	}
	pthread_exit((void*)"Listo");
}

