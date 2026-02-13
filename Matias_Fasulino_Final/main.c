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

/*PANEL*/

int main(int argc, char* argv[]) {
	
	int id_cola_mensajes;
	int i, done=0;
	Pais *datos_pais;
	int* memoria = NULL;
	int id_memoria, id_semaforo;
	int id_pais, disparo;
	mensaje msg;
	char nombre[20], ganador[20];
	int id_pais_enemigo;

	memset(nombre, 0x00, sizeof(nombre));
	memset(ganador, 0x00, sizeof(ganador));

	id_cola_mensajes = creo_id_cola_mensajes();
	borrar_mensajes(id_cola_mensajes);
	id_semaforo = creo_semaforo();
	memoria = (int*) creo_memoria(sizeof(int), &id_memoria, CLAVE_BASE);

	datos_pais = (Pais*) (memoria+1);

	srand(time(NULL));

	*memoria += 1;
	printf("Esperando que todos los procesos esten corriendo...\n");

	if(*memoria==1) {
		espera_semaforo(id_semaforo);
	} else {
		levanta_semaforo(id_semaforo);
	}
	
	while(done<2) {
		
		recibir_mensaje(id_cola_mensajes, MSG_TABLERO, &msg);

		switch(msg.int_evento) {
			
			case EVT_DISPARAR:

				sscanf(msg.char_mensaje, "%d-%d-%d-%s", &id_pais, &disparo, &id_pais_enemigo, nombre);
				printf("%d (%s) - Ataco a: %d con disparo: %d \n", id_pais, nombre, id_pais_enemigo, disparo);

				if( datos_pais[id_pais_enemigo].barcos_vivos == 0) {
					printf("\n--- La flota %s ha sido eliminada ---\n", datos_pais[id_pais_enemigo].nombre);
				} else {					
					for(i=0; i<CANTIDAD_BARCOS; i++) {
						if (datos_pais[id_pais_enemigo].barcos[i].nro_asignado == disparo) {
							printf("\tBarco %s ha sido hundido\n", datos_pais[id_pais_enemigo].nombre);
							datos_pais[id_pais_enemigo].barcos[i].hundido = 1;
							datos_pais[id_pais_enemigo].barcos_vivos--;
						} else {
							printf("\tNingun barco ha sido hundido\n");
						}
					}
				}

				break;
			case EVT_FIN:
				printf("\nEVENTO FIN\n");
				done += 1;
				break;
			default:
				printf("\nEvento sin definir\n");
				break;
		}
	
		sleep(1);
	};

	for(i=0; i<CANTIDAD_PAISES; i++) {
		if(datos_pais[i].barcos_vivos > 0 ) {
			strcpy(ganador, datos_pais[i].nombre);
		}
	}

	printf("\nFIN DE LA PARTIDA. HA GANADO LA FLOTA %s\n", ganador);

	liberar_memoria((char*)memoria, id_memoria);

	printf("\n");
	return 0;
}
