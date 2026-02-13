#ifndef _GLOBAL
#define _GLOBAL

#include <pthread.h>

typedef struct mistruct 
{
	int inEntero;
}MISTRUCT;

typedef struct tipo_dato dato;
struct tipo_dato
{
	int numero;
	char letra;
};

typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
	long long_dest; /*Destinatario*/
	int int_rte;/*Remitente*/
	int int_evento;/*Numero de evento*/
	char char_mensaje[1024];/*mensajse*/
};

struct thread_data
{
	int *id_jugador;
	int num_alea;
	int acierto;
};

struct thread_data data;



typedef struct tipo_barco Barco;
struct tipo_barco
{
	int id_barco;
	int nro_asignado; /*numero para hundir el barco*/
	int hundido;
};

typedef struct tipo_jugador Pais;
struct tipo_jugador
{
	int id_pais;
	char nombre[20];
	Barco barcos[5];
	int barcos_vivos;
	int id_cola_msg;
};



extern int ginEnteroP;

#endif
