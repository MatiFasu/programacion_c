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
#include <thread.h>

/*PANEL*/

int main(int argc, char* argv[]) {
	
	mensaje msg;
	votos s_votos = {0};
	int id_cola_mensajes;
	int id_semaforo;
	int votos = 0;

	id_cola_mensajes = creo_id_cola_mensajes();
	borrar_mensajes(id_cola_mensajes);
	
	id_semaforo = creo_semaforo();

	inicia_semaforo(id_semaforo, VERDE);

	enviar_mensaje(id_cola_mensajes, MSG_VOTANTE, MSG_PANEL, EVT_INICIO, -1, -1);

	while(votos < CANT_VOTOS)
	{	
		espera_semaforo(id_semaforo);
		
		if(recibir_mensaje(id_cola_mensajes, MSG_PANEL, &msg) != -1) {
			procesar_evento_panel(id_cola_mensajes, msg, &s_votos, &votos);
		}

		system("clear");
		printf("Votos para señor MS: %d\nVotos para señor MI: %d\nVotos para señor A: %d\nVotos para señora: %d\n", s_votos.presidente1, 			s_votos.presidente2, s_votos.vice1, s_votos.vice2);

		levanta_semaforo(id_semaforo);
		sleep(5);
	}


	printf("\n");
	return 0;
}
