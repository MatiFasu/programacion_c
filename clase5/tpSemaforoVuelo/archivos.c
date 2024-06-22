#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time.h"
#include "unistd.h"
#include <archivos.h>
#include <def.h>

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
	char producto[100];	

	puts("Leer archivo:");
	while(!feof(f)) {
		fscanf(f,"%s \n", producto);
		printf("%s \n", producto);
	}	

}

void escribirArchivo(FILE* f, int vuelo, char *destino, char *nombre)
{
	fprintf(f,"%d,%s,%s\n", vuelo, destino, nombre);
	
}

int escribirArchivoPorLinea(char *szTextoAEscribir)
{
	return 0;
}

void renombrarArchivo(char *archivo, char *nuevo_archivo)
{
	int res = rename(archivo, nuevo_archivo);
	if(res == 0)
	{
		printf("Archivo renombrado");
	} else {
		printf("Archivo no renombrado");
	}
}




