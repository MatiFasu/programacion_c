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
	int id_persona;
	int done=1;
	char cadena[50];
	char nombre[20];
	int i;
	int cantidad_jugadores;
	int mililitros, id_vino, le_gusto_vino, seguir_tomando;
	
	Persona *datos_persona = (Persona*) parametro;
	id_persona = datos_persona->id_persona;
	id_cola_mensajes = datos_persona->id_cola_msg;

	
	while(done) {
		printf("\nBloquear\n");
		pthread_mutex_lock(&mutex);
		
		if( datos_persona->total_consumido <= 1500) {
			if( datos_persona->total_consumido >=1000 && datos_persona->total_consumido <=1000) {
				printf("HA superado los 1000 ml\n");
				seguir_tomando = devolverAleatorio(0,1);
				if( seguir_tomando==0 ) {
					printf("Persona se retira");
					sprintf(cadena, "Persona se retira");
					enviar_mensaje(id_cola_mensajes, MSG_BODEGA, MSG_PERSONA+datos_persona->id_persona, EVT_FIN, cadena);
				}			
			}
			
			mililitros = devolverAleatorio(1000, 1500);
			id_vino = devolverAleatorio(0,4);
			le_gusto_vino = devolverAleatorio(1,2);				

			printf("Persona %d ha tomado %d mililitros (Vino %d) - Vino bueno: %d\n", id_persona, mililitros, id_vino, le_gusto_vino);

			sprintf(cadena, "%d-%d-%d-%d", id_persona, mililitros, id_vino, le_gusto_vino);
			enviar_mensaje(id_cola_mensajes, MSG_BODEGA, MSG_PERSONA+datos_persona->id_persona, EVT_TOMAR, cadena);
		}
		else {
			/*SI TOMO EN EXCESO MANDO AL EVENTO FIN*/
			printf("Persona %d ha tomado en exceso, SACAR!", datos_persona->id_persona);
			enviar_mensaje(id_cola_mensajes, MSG_BODEGA, MSG_PERSONA+datos_persona->id_persona, EVT_FIN, cadena);
		}
		

		pthread_mutex_unlock(&mutex);
		printf("\nDesbloquear\n");
		sleep(5);		
	};
	


	pthread_exit((void*)"Listo");
}

