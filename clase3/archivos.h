#ifndef _ARCHIVOS
#define _ARCHIVOS

FILE* abrirArchivo(FILE* fp, char *szNombreArchivo, char *szModo);

void cerrarArchivo(FILE* fp);

void leerArchivo(FILE* fp);

void escribirArchivo(FILE* fp, char* contenido);

int escribirArchivoPorLinea(char *szTextoAEscribir);

int getCant(FILE* f);

#endif
