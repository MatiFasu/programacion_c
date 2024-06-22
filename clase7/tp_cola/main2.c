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

/*CAJERO*/

void procesar_evento(int id_cola_msg, mensaje msg);

int main(int argc, char* argv[]) {

	int id_cola_msg;
	int seleccion;
	int nro_cuenta;
	int monto;

	mensaje msg;

	id_cola_msg = creo_id_cola_mensajes();

	while(1)
	{
		printf("Ingrese: \n1. Consulta\n2. Deposito\n3. Extraccion\n0. Salir\n");
		scanf("Respuesta: %d", &seleccion);
		
		if(seleccion!=0) {
			printf("\nIngrese nro de cuenta: ");
			scanf("%d", &nro_cuenta);
		}

		switch(seleccion) {
	
			case 1:
				enviar_mensaje(id_cola_msg, MSG_BANCO, MSG_CAJERO, EVT_CONSULTA_SALDO, nro_cuenta, -1, "Consulta Saldo");
				break;
			case 2:
				printf("\nIngrese monto a depositar: ");
				scanf("%d", &monto);
				enviar_mensaje(id_cola_msg, MSG_BANCO, MSG_CAJERO, EVT_DEPOSITO, nro_cuenta, monto, "Solicito hacer deposito");
				break;
			case 3:
				printf("\nIngrese monto a extraer: ");
				scanf("%d", &monto);
				enviar_mensaje(id_cola_msg, MSG_BANCO, MSG_CAJERO, EVT_EXTRACCION, nro_cuenta, monto, "Solicito hacer extraccion");
				break;
			case 0:
				return 0;

		}
		
		recibir_mensaje(id_cola_msg, MSG_CAJERO, &msg);
		procesar_evento(id_cola_msg, msg);
		
		sleep(5);
	}	
			
	printf("\n");
	return 0;
}

void procesar_evento(int id_cola_msg, mensaje msg)
{
	switch(msg.int_evento) {
		
		case EVT_RTA_SALDO:
			printf("\nSaldo de la cuenta: %d\n", msg.monto);
			break;

		case EVT_RTA_SALDO_NOK:
			printf("\nNo se pudo realizar la consulta\n");
			printf("Error: %s\n", msg.char_mensaje);
			break;

		case EVT_RTA_DEPOSITO:
			printf("\nNuevo saldo: %d\n", msg.monto);
			break;
				
		case EVT_RTA_DEPOSITO_NOK:
			printf("\nHubo un error al realizar el deposito");
			printf("Error: %s", msg.char_mensaje);
			break;		
				
		case EVT_RTA_EXTRACCION:
			printf("\nSaldo restante: %d\n", msg.monto);
			break;
		
		case EVT_RTA_EXTRACCION_NOK:
			printf("\nHubo un error al realizar la extraccion");
			printf("Error: %s", msg.char_mensaje);
			break;

		default:
			printf("\nEvento sin definit");
			break;
	}
	
	printf("---------------------------\n");
}






