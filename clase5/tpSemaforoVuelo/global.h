#ifndef _GLOBAL
#define _GLOBAL

typedef struct vuelo 
{
	int v;
	char destino[30+1];
	char nombre[30+1];
}Vuelo;

typedef struct reserva 
{
	int vuelo;
	char destino[30+1];
	int cant_p;
}Reserva;


extern int ginEnteroP;

#endif
