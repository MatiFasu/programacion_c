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

/*PIENSO*/

int main(int argc, char* argv[]) {
	
	int pienso_num;
	int id_cola_mensajes;
	int num_recibido;
	int nro_jugador;
	int done=0;
	mensaje msg;

	srand(time(NULL));

	pienso_num = devolverAleatorio(1,10);

	printf("\n Pienso num: %d\n", pienso_num);

	id_cola_mensajes = creo_id_cola_mensajes();

	borrar_mensajes(id_cola_mensajes);

	
	while(done==0) {
		recibir_mensaje(id_cola_mensajes, MSG_PIENSO, &msg);
		nro_jugador = msg.int_rte;

		switch(msg.int_evento) {
			
			case EVT_NUMERO:
				num_recibido = atoi(msg.char_mensaje);
				
				if(num_recibido==pienso_num) {
					enviar_mensaje(id_cola_mensajes, MSG_JUGADOR+nro_jugador, MSG_PIENSO, EVT_ACERTO, "FINALIZAR");
					printf("Jugador: %d\n", nro_jugador);
					printf("Has ganado con el numero %d", num_recibido);
					done=1;
				}
				else {
					enviar_mensaje(id_cola_mensajes, MSG_JUGADOR, MSG_PIENSO, EVT_NO_ACERTO, "FINALIZAR");
				}				
	
				break;

			default:
				break;

		}
	}
	

	printf("\n");
	return 0;
}
