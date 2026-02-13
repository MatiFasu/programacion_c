#include "stdlib.h"
#include "stdio.h"
#include "gestorArchivos.h"
#include "global.h"
FILE *archivo;

int openfile(char filename[LARGO_CADENA]){
	if ((archivo=fopen(filename, "a+"))==NULL)
	{
		printf("\n No se pudo abrir el archivo %s", filename);
		return FALSE;
	}else	
		return TRUE;
}
int openfileread(char filename[LARGO_CADENA])
{
	if ((archivo=fopen(filename, "r+"))==NULL)
	{
		printf("\n No se pudo abrir el archivo %s", filename);
		return FALSE;
	}else	
		return TRUE;

}


