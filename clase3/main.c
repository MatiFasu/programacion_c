#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <def.h>
#include <archivos.h>

/*
memcpy -> hace lo que nosotros queremos y le indicamos la cantidad.
strlen: devuelve la longitud y sizeof: devuelve el tamaño

*/


int main(int argc, char* argv[]) {

	/*
	int *inEnteroP;
	char *szCadenaP;

	int inEntero=0;
	char *szCadena="hola";

	para dimensionar la variable, maneja la direccion de memoria
	inEnteroP=(int*) malloc(sizeof(int) * 5);
	szCadenaP=(char*) malloc(sizeof(char) * 20);

	*inEnteroP=10;
	memset(szCadenaP,0x00,sizeof(szCadenaP));
	memcpy(szCadenaP,"hola",4);

	printf("d: %i - %s\n", inEnteroP, szCadenaP);		
	printf("st: %i - %s\n", inEntero, szCadena);
	printf("st: %i - %s\n", &inEntero, &szCadena);

	inEnteroP=&inEntero;
	
	si es estatico le pongo ampersan
	inDevolverEntero(&inEntero);
	si es un puntero no pongo nada
	inDevolverEntero(inEnteroP);

	printf("st: %i - %s\n", &inEnteroP, &szCadenaP);


	
	free(inEnteroP);
	free(szCadenaP);
	

	int numero;
	char *text;

	FILE* f = abrirArchivo(f,"hola.txt","w");
	
	scanf("%d", &numero);
	while(numero !=0 ) {
		sprintf(text, "%d", numero);
		escribirArchivo(f,text);
		scanf("%d",&numero);
	}
	
	cerrarArchivo(f);

	f = abrirArchivo(f,"hola.txt","r");

	leerArchivo(f);
	
	cerrarArchivo(f);*/
	
	int i=0;	

	FILE* f = NULL;

	f = abrirArchivo(f,"hola.txt","r");
	
	i = getCant(f);
	
	cerrarArchivo(f);

	printf("Hay %d lineas\n", i);

	printf("\n");
	return 0;
}
