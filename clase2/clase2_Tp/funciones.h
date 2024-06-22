#ifndef _FUNCIONES
#define _FUNCIONES

struct Arr {
	int* el;
	int len;
};

int devolverAleatorio(int desde, int hasta);

int estaRepetido(struct Arr ar, int numAlea, int longitud);

struct Arr crearArreglo();

struct Arr generarArregloAleatorio(struct Arr ar, int desde, int hasta);

void liberarArreglo(struct Arr ar);

void imprimirArreglo(struct Arr ar);

#endif
