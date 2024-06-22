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

/*BANCO*/

void procesar_evento(int id_cola_msg, mensaje msg, cliente (*cli)[100]);

cliente* procesar_memoria(int id_memoria);

int main(int argc, char* argv[]) {
	
	int id_cola_msg;
	mensaje msg;
	cliente cli[100];
	int i;

	id_cola_msg = creo_id_cola_mensajes();

	srand(time(NULL));

	for(i=0; i<100; i++) {
		cli[i].numero_cliente = i+1;
		cli[i].saldo = devolverAleatorio(100,500);
	}
	
	while(1)
	{
	
		recibir_mensaje(id_cola_msg, MSG_BANCO, &msg);
		procesar_evento(id_cola_msg, msg, &cli);	

	}

	printf("\n");
	return 0;
}

void procesar_evento(int id_cola_msg, mensaje msg, cliente (*cli)[100])
{
	int saldo;
	int num_cliente;
	
	num_cliente = msg.nro_cuenta;

	switch(msg.int_evento)
	{
		case EVT_CONSULTA_SALDO:	
			printf("Consulta saldo numero cuenta: %d\n", msg.nro_cuenta);
			if(num_cliente>=0 && num_cliente<100) {
				saldo = (*cli)[num_cliente].saldo;
				enviar_mensaje(id_cola_msg, msg.int_rte, MSG_BANCO, EVT_RTA_SALDO, num_cliente, saldo, "Consulta exitosa");
			}	
			else {
				enviar_mensaje(id_cola_msg, msg.int_rte, MSG_BANCO, EVT_RTA_SALDO_NOK, -1, -1, "El cliente no existe");
			}
			break;

		case EVT_DEPOSITO:
			printf("Pedido deposito\n");
			if(num_cliente>=0 && num_cliente<=100) {
				(*cli)[num_cliente].saldo = (*cli)[num_cliente].saldo + msg.monto;
				saldo = (*cli)[num_cliente].saldo;
				enviar_mensaje(id_cola_msg, msg.int_rte, MSG_BANCO, EVT_RTA_DEPOSITO, num_cliente, saldo, "Deposito exitoso");
			}	
			else {
				enviar_mensaje(id_cola_msg, msg.int_rte, MSG_BANCO, EVT_RTA_DEPOSITO_NOK, -1, -1, "El cliente no existe");
			}
			break;

		case EVT_EXTRACCION:
			printf("Pedido de extraccion\n");
			if(num_cliente>=0 && num_cliente<=100) {
				
				if( (*cli)[num_cliente].saldo < msg.monto ) {
					enviar_mensaje(id_cola_msg, msg.int_rte, MSG_BANCO, EVT_RTA_EXTRACCION_NOK, -1, -1, "El saldo de la cuenta es 						insuficiente");	
				}
				else {
					(*cli)[num_cliente].saldo = (*cli)[num_cliente].saldo - msg.monto;
					saldo = (*cli)[num_cliente].saldo;
					enviar_mensaje(id_cola_msg, msg.int_rte, MSG_BANCO, EVT_RTA_DEPOSITO, num_cliente, saldo, "Extraccion exitosa");
				}
			}
			else {	
				enviar_mensaje(id_cola_msg, msg.int_rte, MSG_BANCO, EVT_RTA_EXTRACCION_NOK, -1, -1, "El cliente no existe");
			}	
			
			break;

		default:
			printf("Evento sin definir");
			break;
	}
	
	printf("--------------------------------\n");

}	

cliente* procesar_memoria(int id_memoria)
{
	cliente *memoria = NULL;
	int i;

	srand(time(NULL));

	memoria = (cliente*)creo_memoria(sizeof(cliente)*CANT, &id_memoria, CLAVE_BASE);

	for(i=0; i<100; i++)
	{
		memoria[i].numero_cliente = i+1;
		memoria[i].saldo = devolverAleatorio(100,900);
	}

	return memoria;
}






