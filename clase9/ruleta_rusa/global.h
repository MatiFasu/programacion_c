#ifndef _GLOBAL
#define _GLOBAL

#include <pthread.h>

typedef struct tipo_mensajes mensaje;
struct tipo_mensajes
{
	long long_dest; /*Destinatario*/
	int int_rte;/*Remitente*/
	int int_evento;/*Numero de evento*/
	char char_mensaje[1024];/*mensajse*/
};





extern int ginEnteroP;

#endif
