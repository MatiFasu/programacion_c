#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

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

/*
Cola de mensajes -> esto si es una llamada entre procesos, no como los archivos (que sirven para escribir archivos) o memoria compartida (sirve para guardar variables)
La comunicacion es unidireccional
*/

#define DESDE 10
#define HASTA 20
#define INTERVALO 5

#define MSG_JOSE 		1
#define MSG_PEPITO		2

#define EVT_MENSAJE		1
#define EVT_FIN			2

int main(int argc, char* argv[]) {

	int id_cola_mensajes;
	mensaje	msg;	
	msg.int_evento = 0;
	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	
	printf("\nSOY DON PEPITO  \n");


	while(msg.int_evento!=EVT_FIN)
	{
		recibir_mensaje(id_cola_mensajes, MSG_PEPITO, &msg);
		printf("Destino   %d\n", (int) msg.long_dest);
		printf("Remitente %d\n", msg.int_rte);
		printf("Evento    %d\n", msg.int_evento);
		printf("Mensaje   %s\n", msg.char_mensaje);
		switch (msg.int_evento)
		{
			case EVT_MENSAJE:
				printf("Recibi el EVT_MENSAJE\n");
				/*printf("Mensaje   %s\n", msg.char_mensaje);*/
				sleep(INTERVALO);
				if(strcmp(msg.char_mensaje, "HOLA DON PEPITO")==0)
					enviar_mensaje(id_cola_mensajes , msg.int_rte, MSG_PEPITO, EVT_MENSAJE, "HOLA DON JOSE");
				else if(strcmp(msg.char_mensaje, "PASO USTED POR CASA")==0)
					enviar_mensaje(id_cola_mensajes , msg.int_rte, MSG_PEPITO, EVT_MENSAJE, "POR SU CASA YO PASE");
				else if(strcmp(msg.char_mensaje, "VIO USTED A MI ABUELA")==0)
					enviar_mensaje(id_cola_mensajes , msg.int_rte, MSG_PEPITO, EVT_MENSAJE, "A SU ABUELA YO LA VI");
			break;
			case EVT_FIN:
				enviar_mensaje(id_cola_mensajes , msg.int_rte, MSG_PEPITO, EVT_FIN, "ADIOS DON JOSE");
				printf("Recibi el EVT_FIN\n");
			break;
			default:
				printf("\nEvento sin definir\n");
			break;
		}
		printf("------------------------------\n");
	}

	if(msg.int_evento!=EVT_FIN)	
		enviar_mensaje(id_cola_mensajes, MSG_JOSE, MSG_PEPITO, EVT_FIN, "");
			


	printf("\n");
	return 0;
}
