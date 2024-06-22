#ifndef _ARCHIVOS
#define _ARCHIVOS

FILE* abrirArchivo(FILE* fp, char *szNombreArchivo, char *szModo);

void cerrarArchivo(FILE* fp);

void leerArchivo(FILE* fp);

void escribirArchivo(FILE* f, int vuelo, char *destino, char *nombre);

int escribirArchivoPorLinea(char *szTextoAEscribir);

void renombrarArchivo(char *archivo, char *nuevo_archivo);

#endif
