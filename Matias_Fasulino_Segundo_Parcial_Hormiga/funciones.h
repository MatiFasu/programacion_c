#ifndef _FUNCIONES
#define _FUNCIONES
#include <global.h>

struct Arr {
	int* el;
	int len;
};

void inicializarVariables();

int devolverAleatorio(int desde, int hasta);

int estaRepetido(struct Arr ar, int numAlea, int longitud);

struct Arr crearArreglo();

struct Arr generarArregloAleatorio(struct Arr ar, int desde, int hasta);

void liberarArreglo(struct Arr ar);

void imprimirArreglo(struct Arr ar);

int procesar_evento_panel(int, mensaje);

int procesar_evento_animal(int, mensaje);

#endif
