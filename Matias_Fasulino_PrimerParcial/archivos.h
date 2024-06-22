#ifndef _ARCHIVOS
#define _ARCHIVOS

struct equipo {
	char nombreEquipo[50];
	int goles;
	int afueras;
};


FILE* abrirArchivo(FILE* fp, char *szNombreArchivo, char *szModo);

void cerrarArchivo(FILE* fp);

void leerArchivo(FILE* fp);

void escribirArchivo(FILE* fp, char* contenido);

int escribirArchivoPorLinea(char *szTextoAEscribir);

void escribirArchivo1(FILE* f, struct equipo e, int remate, int remateAleatorio);

void escribirArchivo2(FILE* f, struct equipo e, char* gana);

int getCant(FILE* file);

#endif
