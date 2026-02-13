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

typedef struct tipo_animal Hormiga;
struct tipo_animal
{
	int id_hormiga;
	int id_cola_msg;
	char nombre[50];
	int velocidad_min;
	int velocidad_max;
	int cantidad_pasos;
};

extern int ginEnteroP;

#endif
