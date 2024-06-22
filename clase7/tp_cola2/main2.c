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

	int id_cola_mensajes;
	mensaje msg;
	int seleccion;
	int nro_cuenta, monto;

	id_cola_mensajes = creo_id_cola_mensajes();

	while(1) 
	{
		printf("Ingrese: \n1. Consulta\n2. Deposito\n3. Extraccion\n0. Salir\nRespuesta: ");		
		scanf("%d", &seleccion);

		if(seleccion!=0) {
			printf("\nIngrese nro cuenta: ");
			scanf("%d", &nro_cuenta);
		}

		switch(seleccion) {

			case 1:
				enviar_mensaje(id_cola_mensajes, MSG_BANCO, MSG_CAJERO, EVT_CONSULTA_SALDO, nro_cuenta, -1, "Consulta saldo");
				break;
			case 2:
				printf("\nIngresar monto a depositar: ");
				scanf("%d", &monto);
				enviar_mensaje(id_cola_mensajes, MSG_BANCO, MSG_CAJERO, EVT_DEPOSITO, nro_cuenta, monto, "Solicito hacer un deposito");
				break;
			case 3:
				printf("\nIngresar monto a extraer: ");
				scanf("%d", &monto);
				enviar_mensaje(id_cola_mensajes, MSG_BANCO, MSG_CAJERO, EVT_EXTRACCION, nro_cuenta, monto, "Solicito hacer una 					extraccion");
				break;
			case 0:
				return 0;	
	
		}
		
		recibir_mensaje(id_cola_mensajes, MSG_CAJERO, &msg);		
		procesar_evento(id_cola_mensajes, msg);
		sleep(3);
	}
	
			
	printf("\n");
	return 0;
}

void procesar_evento(int id_cola_msg, mensaje msg)
{
	int id_memoria;
	cliente *memoria = NULL;
	
	memoria = (cliente*)creo_memoria(sizeof(cliente)*100, &id_memoria, CLAVE_BASE);

	switch(msg.int_evento) {
		
		case EVT_RTA_SALDO:
			printf("\nSaldo de la cuenta: %d", memoria[msg.nro_cuenta].saldo);
			break;
		case EVT_RTA_SALDO_NOK:
			printf("\nNo se pudo realizar la consulta");
			break;
		case EVT_RTA_DEPOSITO:
			printf("\nNuevo saldo: %d", memoria[msg.nro_cuenta].saldo);
			break;
		case EVT_RTA_DEPOSITO_NOK:
			printf("\nNo se pudo realizar el deposito");
			break;
		case EVT_RTA_EXTRACCION:
			printf("\nSaldo restante: %d", memoria[msg.nro_cuenta].saldo);
			break;
		case EVT_RTA_EXTRACCION_NOK:
			printf("\nNo se pudo realizar la extraccion");
			break;
		default:
			printf("\nEvento sin definir");
			break;
	}
	
	printf("\n--------------------------\n");
}






