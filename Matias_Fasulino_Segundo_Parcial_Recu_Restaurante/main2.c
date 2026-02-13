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

/*MOZO*/

int main(int argc, char* argv[]) {

	int id_cola_mensajes;
	int i;
	int cantidad=CANTIDAD_MOZOS;
	int *memoria = NULL;
	int id_memoria, id_semaforo;
	char cadena[50];

	Mozo *datos_mozo;
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
		printf("Arranca el proceso\n");
		levanta_semaforo(id_semaforo);
	}

	id_cola_mensajes = creo_id_cola_mensajes();
	borrar_mensajes(id_cola_mensajes);

	idHilo = (pthread_t*)malloc(sizeof(pthread_t)*cantidad);
	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

	datos_mozo = (Mozo*)malloc(sizeof(Mozo)*cantidad);
	
		/* Lanzo Mozo1 */
		datos_mozo[0].id_mozo = 0;
		datos_mozo[0].id_cola_msg = id_cola_mensajes;
		pthread_create(&idHilo[0], &atributos, funcionThread, &datos_mozo[0]);
		/* Lanzo Mozo2 */
		datos_mozo[1].id_mozo = 1;
		datos_mozo[1].id_cola_msg = id_cola_mensajes;
		pthread_create(&idHilo[1], &atributos, funcionThread, &datos_mozo[1]);
		/* Lanzo Mozo3 */
		datos_mozo[2].id_mozo = 2;
		datos_mozo[2].id_cola_msg = id_cola_mensajes;
		pthread_create(&idHilo[2], &atributos, funcionThread, &datos_mozo[2]);

	for(i=0; i<cantidad; i++) {
		pthread_join(idHilo[i], NULL);
		printf("FIN\n");
		sprintf(cadena, "Se termino");
		enviar_mensaje(id_cola_mensajes, MSG_RESTAURANTE, MSG_RESTAURANTE, EVT_FIN, cadena);
	}	


	liberar_memoria((char*)memoria, id_memoria);
	
	printf("\n");
	return 0;
}
