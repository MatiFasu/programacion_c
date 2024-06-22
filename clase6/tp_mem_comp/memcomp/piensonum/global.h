#ifndef _global
#define _global

#define CLAVE_GLOBAL 33
#define VERDE 1
#define ROJO 0
#define LARGO_CADENA 100+1
#define TRUE 1
#define FALSE 0
#define TAMANIOMEM 10

typedef struct juego
{
	char nombre_jugador[LARGO_CADENA];
	int numero_pensado;
	int estado_acierto;
}juego;

#endif
