#ifndef _ARCHIVO 
#define _ARCHIVO
int inAbrirArchivo(char *szNombre, char *szModo);
int inLeerArchivo(char *szNombre, char *szModo);
int inEscribirArchivo(char *szNombre, char *szModo, char *sztexto);
int inContarLineas(char *szNombre);
int inEliminarLineas(char *szNombre,int cantidadEliminar);
int inRenombrarArchivoTemp(char *szNombre);
int inBorrarArchivo(char *szNombre);
int inCrearArchivo(char *szNombre);
int inAbrirTemp(char *szNombre, char *szModo);
int leerUltimaLinea(char *szNombre, char *szModo, char *ultimaLinea);
void voCerrarTemp();
void voCerrarArchivo();
int inRenombrarArchivo(char *szSource,char *szDest);
#endif
 
