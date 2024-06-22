#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
	char texto[100];

	printf("Datos del archivo: \n");
	while(!feof(f)) {
		fscanf(f," %s \n", texto);
		printf("%s \n", texto);	
	}	
}

void escribirArchivo(FILE* f, char *contenido)
{
	fprintf(f, "%s", contenido);
}

int escribirArchivoPorLinea(char *szTextoAEscribir)
{
	return 0;
}

int getCant(FILE* f)
{
	char producto[100];
	int i=0;

	while( fgets(producto, sizeof(producto), f) ) {
		i++;
	}

	return i;
}




