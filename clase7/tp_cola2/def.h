#ifndef _DEF
#define _DEF

typedef enum 
{
	MSG_NADIE,
	MSG_BANCO,
	MSG_CAJERO
}Destinos;

typedef enum
{
	/*BANCO*/
	EVT_NINGUNO,
	EVT_CONSULTA_SALDO,
	EVT_DEPOSITO,
	EVT_EXTRACCION,
	/*CAJERO*/
	EVT_RTA_SALDO,
	EVT_RTA_SALDO_NOK,
	EVT_RTA_DEPOSITO,
	EVT_RTA_DEPOSITO_NOK,
	EVT_RTA_EXTRACCION,
	EVT_RTA_EXTRACCION_NOK
}Eventos;

#define DESDE 10
#define HASTA 20

#define CANT_ARR 10

#define CANTIDAD 10

#define LARGO 100

#define CANTIDAD_PARTIDA 10

#define INTERVALO_PARTIDA 5000

#define INTERVALO_PRODUCTO 100

#define TRUE 1
#define FALSE 0

#define VERDE 1
#define ROJO 0

#define CLAVE_BASE 45

#define CANT 10

#define CANT_TOTAL 10

#define LARGO_TMENSAJE 1024

#endif
