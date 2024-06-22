#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include <funciones.h>
#include <definiciones.h>

int devolverAleatorio(int desde, int hasta)
{
	return (rand() % (hasta - desde	+ 1)) + desde;	
}

int estaRepetido(int numArr[], int numAlea, int longitud) 
{
	int i;		
	
	for(i=0; i<longitud; i++) {
		if(numArr[i]==numAlea) {
			return 1;
		}
	}
	
	return 0;
}



