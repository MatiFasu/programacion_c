#ifndef _GLOBAL
#define _GLOBAL

#include <pthread.h>

pthread_mutex_t mutex;

typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
	long long_dest; /*Destinatario*/
	int int_rte;/*Remitente*/
	int int_evento;/*Numero de evento*/
	int presidente;
	int vice_presidente;
};

typedef struct votos_data votos;
struct votos_data
{
	int presidente1;
	int vice1;
	int presidente2;
	int vice2;
};




extern int ginEnteroP;

#endif
