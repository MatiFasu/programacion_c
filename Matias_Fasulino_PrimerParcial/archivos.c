#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time.h"
#include "unistd.h"
#include <archivos.h>
#include <def.h>
#include <global.h>

FILE* abrirArchivo(FILE *fp,char *szNombreArchivo, char *szModo)
{
	
	fp=fopen(szNombreArchivo, szModo);
	if(fp==NULL) {
		printf("Falla al abrir archivo");
		return NULL;
	} else {
		return fp;
	}
}

void cerrarArchivo(FILE* fp)
{
	fclose(fp);
}

void leerArchivo(FILE *f)
{
	char producto[15];

	/*puts("Consumir productos:");*/
	while(!feof(f)) {
		fscanf(f,"%s ", producto);
		printf("%s ", producto);
	}	
}

void escribirArchivo(FILE* f, char *contenido)
{
	int i=0, cant=10;
	for(i=0; i<cant; i++) {
		fprintf(f,contenido,i+1);
	}

}

int escribirArchivoPorLinea(char *szTextoAEscribir)
{
	return 0;
}

void escribirArchivo1(FILE* f, struct equipo e, int remate, int remateAleatorio)
{
	if(remate == remateAleatorio) {
		fprintf(f, "GOL!, Equipo: %s, Goles: %d, Afueras: %d, %d = %d\n", e.nombreEquipo, e.goles, e.afueras, remate, remateAleatorio);
	} else {
		fprintf(f, "AFUERA!, Equipo: %s, Goles: %d, Afueras: %d, %d! = %d\n", e.nombreEquipo, e.goles, e.afueras, remate, remateAleatorio);
	}
}

void escribirArchivo2(FILE* f, struct equipo e, char* gana)
{
	fprintf(f, "Equipo: %s, %s, Goles: %d \n", e.nombreEquipo, gana, e.goles);
}

int getCant(FILE* f)
{
	int i=0;

	while(!feof(f) ) {
		i++;
	}

	return i;
}


