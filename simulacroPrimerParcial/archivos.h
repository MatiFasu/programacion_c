#ifndef _ARCHIVOS
#define _ARCHIVOS

struct alumno {
	int tipoAlumno;
	int cantMat;
	char nombreApellido[50];
};


FILE* abrirArchivo(FILE* fp, char *szNombreArchivo, char *szModo);

void cerrarArchivo(FILE* fp);

void leerArchivo(FILE* fp);

void escribirArchivo(FILE* fp, char* contenido);

int escribirArchivoPorLinea(char *szTextoAEscribir);

void escribirArchivo1(FILE* f, struct alumno a);

void escribirArchivo2(FILE* f, struct alumno a);

int getCant(FILE* file);

#endif
