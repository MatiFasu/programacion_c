#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <funciones.h>
#include <def.h>
#include "global.h"


void inicializarVariables()
{
	ginEnteroP = 0;
}

int devolverAleatorio(int desde, int hasta)
{
	return (rand() % (hasta - desde	+ 1)) + desde;	
}

int estaRepetido(struct Arr ar, int numAlea, int longitud) 
{
	int i;		
	
	for(i=0; i<longitud; i++) {
		if(ar.el[i]==numAlea) {
			return 1;	
		}
	}
	
	return 0;
}

struct Arr crearArreglo() 
{
	struct Arr arr;

	arr.len = CANT_ARR;

	arr.el = (int*)malloc(CANT_ARR * sizeof(int));

	return arr;
}

struct Arr generarArregloAleatorio(struct Arr ar, int desde, int hasta)
{
	int i, numAlea;
	for(i=0; i<CANT_ARR; i++) {

		do {
			
			numAlea = devolverAleatorio(desde, hasta);
			
		} while (estaRepetido(ar, numAlea, i)); 

		ar.el[i] = numAlea; 
	}

	return ar;
}

void liberarArreglo(struct Arr ar)
{
	free(ar.el);
}

void imprimirArreglo(struct Arr ar)
{
	int i;
	printf("Arreglo: \n");
	for(i=0; i<CANT_ARR; i++) {
		printf("- %d \n", ar.el[i]);
		sleep(1);
	}
}

int procesar_evento_panel(int id_cola_mensajes, mensaje msg)
{
	int done = 0;
	
	switch(msg.int_evento) {

		case EVT_CORRO:
			printf("\nEMPIEZAN a correr\n");
			break;
		case EVT_FIN:
			printf("\nTermina carrera\n");
			done=1;
			break;
		default:
			break;	

	}
	

	return done;
}

int procesar_evento_animal(int id_cola_mensajes, mensaje msg)
{
	switch(msg.int_evento) {
		case EVT_CORRO:
			break;
		case EVT_FIN:
			printf("\nFin\n");
			return 1;
	}
}


