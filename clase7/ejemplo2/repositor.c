
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

#define INTERVALO_PEDIDOS 2000

void procesar_evento(int id_cola_mensajes, mensaje msg, int i)
{
	printf("Evento %d\n", i);
	printf("Destino   %d\n", (int) msg.long_dest);
	printf("Remitente %d\n", msg.int_rte);
	printf("Evento    %d\n", msg.int_evento);
	printf("Mensaje   %s\n", msg.char_mensaje);
	switch (msg.int_evento)
	{
		case EVT_RESPUESTA_STOCK:
			printf("Rta stock\n");
			printf("STOCK %d\n", atoi(msg.char_mensaje));
		break;

		default:
			printf("\nEvento sin definir\n");
		break;
	}
	printf("------------------------------\n");
}

int main()
{
	int id_cola_mensajes, i=1;
	mensaje	msg;

	id_cola_mensajes = creo_id_cola_mensajes(CLAVE_BASE);
	
	while(1)
	{
		enviar_mensaje(id_cola_mensajes , MSG_SUPERMERCADO, MSG_REPOSITOR, EVT_SUMA_STOCK, "SUMA UNO");
		enviar_mensaje(id_cola_mensajes , MSG_SUPERMERCADO, MSG_REPOSITOR, EVT_CONSULTA_STOCK, "DECIME EL STOCK POR FAVOR");
		recibir_mensaje(id_cola_mensajes, MSG_REPOSITOR, &msg);
		procesar_evento(id_cola_mensajes, msg, i);
		i++;
		usleep (INTERVALO_PEDIDOS*1000);
	};
	
	return 0;
}
