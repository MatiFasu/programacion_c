#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <funciones.h>
#include <definiciones.h>



int main(int argc, char* argv[]) {
	

	int desde = atoi(argv[1]);
	int hasta = atoi(argv[2]);

	struct Arr ar = crearArreglo();
		
	ar = generarArregloAleatorio(ar, desde, hasta);

	imprimirArreglo(ar);
	
	printf("\n");	
	
	liberarArreglo(ar);

	return 0;
}
