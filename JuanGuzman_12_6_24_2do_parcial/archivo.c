#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#include "global.h"
#include "def.h"
#include "archivo.h"

/*GLOBAL FILE HANDLE*/
int inAbrirArchivo(char *szNombre, char *szModo){
	
	fileHandle = fopen(szNombre,szModo);

	if(fileHandle == NULL){
		printf("FILE %s TODAVIA NO FUE CREADO\nMODO DE ACCESO %s",szNombre,szModo);
		printf("\n");
		return 0;
	}
	else{
		return 1;
	}
}

void voCerrarArchivo(){
	fclose(fileHandle);
} 

int inLeerArchivo(char *szNombre, char *szModo){
	int openResult = 0;
	char buffer[64];
	
	openResult = inAbrirArchivo(szNombre,szModo);

	if(openResult == 0)
		return 0;
	

	while(fgets(buffer,64,fileHandle)){
		printf("%s",buffer);
	}
	printf("\n");
	
	voCerrarArchivo(szNombre);
	return 1;
}	

int inEscribirArchivo(char *szNombre, char *szModo, char *sztexto){
	int openResult = 0;	
	
	openResult = inAbrirArchivo(szNombre,szModo);

	if(openResult == 0)
		return 0;

	fprintf(fileHandle,"%s\n",sztexto);
	
	voCerrarArchivo(szNombre);

	return 1;
}

int inContarLineas(char *szNombre){
	char buffer[64];
	int openResult = 0;
	int counter = 0;

	openResult = inAbrirArchivo(szNombre,"r");

	if(openResult == 0)
		return 0;

	while(fgets(buffer,64,fileHandle) != NULL)
		counter++;
	
	voCerrarArchivo(szNombre);

	return counter;
}

int inEliminarLineas(char *szNombre,int cantidadEliminar){
	int openMain = 0;
	int createTemp= 0;
	int openTemp = 0;
	int borrarMain = 0;
	int renombrar = 0;
	int cantidadTotalLineas = 0;
	int cantidadRequerida = 0;
	int counter = 0;
	char tempFile[10] = "temp.txt";
	char buffer[1000];
	
	/*cuento lineas en archivo szNombre*/
	cantidadTotalLineas = inContarLineas(szNombre);

	/*obtengo cantidad de lineas que no necesito borrar*/
	cantidadRequerida = cantidadTotalLineas - cantidadEliminar;
	
	/*creo archivo temp*/
	createTemp = inCrearArchivo(tempFile);
	printf("createTemp: %d \n",createTemp);
	if(createTemp == 0) return 0;

	/*abro archivo szNombre para leer*/
	openMain = inAbrirArchivo(szNombre,"r");
	printf("openMain: %d \n",openMain);
	if(openMain == 0) return 0;

	openTemp = inAbrirTemp(tempFile,"w");
	printf("openTemp: %d \n",openTemp);
	if(openTemp == 0) return 0;

	while(fgets(buffer,64,fileHandle) && counter < cantidadRequerida){
		counter += 1;
		fprintf(fileTemp,"%s",buffer);
	}

	/*cierro archivos szNombre y temp*/
	voCerrarArchivo();
	printf("cierro archivo main\n");
	voCerrarTemp();
	printf("cierro archivo temp\n");
	
	/*borro archivo szNombre*/
	borrarMain = inBorrarArchivo(szNombre);
	printf("borro main %d\n",borrarMain);
	if(borrarMain == 0) return 0;

	/*renombre archivo temp con nombre de szNombre*/
	renombrar = inRenombrarArchivoTemp(szNombre);
	printf("renombrarMain %d\n",renombrar);
	if(renombrar == 0) return 0;

	return 1;
}

int inRenombrarArchivoTemp(char *szNombre){
	char tempFileName[10] = "temp.txt" ;

	if(rename(tempFileName,szNombre) == 0)
		return 1;
	
	return 0;	
}

int inRenombrarArchivo(char *szSource,char *szDest){

	if(rename(szSource,szDest) == 0)
		return 1;
	
	return 0;	
}

int inBorrarArchivo(char *szNombre){

	if(remove(szNombre) == 0)
		return 1;
	
	return 0;	
}

int inCrearArchivo(char *szNombre){
	int result = 0;

	result = inAbrirTemp(szNombre,"w");
	voCerrarTemp();

	return result;
}

int inAbrirTemp(char *szNombre, char *szModo){
	
	fileTemp = fopen(szNombre,szModo);

	if(fileTemp == NULL){
		printf("Unable to read from file %s\n",szNombre);
		printf("\n");
		return 0;
	}
	else{
		return 1;
	}
}

void voCerrarTemp(){
	fclose(fileTemp);
} 

int leerUltimaLinea(char *szNombre, char *szModo, char *ultimaLinea){
	int openResult = 0;
	char buffer[64];
	
	
	memset(buffer,0x00,sizeof(buffer));
	openResult = inAbrirArchivo(szNombre,szModo);

	if(openResult == 0)
		return 0;
	

	while(fgets(buffer,64,fileHandle) != NULL);

	memcpy(ultimaLinea,buffer,sizeof(buffer));

	voCerrarArchivo(szNombre);

	return 1;
}








