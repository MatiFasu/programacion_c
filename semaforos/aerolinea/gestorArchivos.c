#include "stdlib.h"
#include "stdio.h"
#include "gestorArchivos.h"
#include "global.h"
#include "string.h"
#include "funciones.h"



int readlote(){
	if ((lote=fopen("lote.dat", "r"))==NULL)
	{
		printf("\nTodavia no se creo un nuevo lote\n");
		return FALSE;
		}else
		fclose(lote);	
		return TRUE;

}
int openfile(char filename[LARGO_CADENA]){
	if ((lote2=fopen(filename, "w"))==NULL)
	{
		printf("\n No se pudo abrir el lote");
		return FALSE;
	}else	
		return TRUE;
}
int openfilelote(){
	if ((lote=fopen("lote.dat", "a+"))==NULL)
	{
		printf("\n No se pudo abrir el lote");
		return FALSE;
	}else	
		return TRUE;
}

void cargavuelo(){
	int vuelo = 0;
	char nombre[LARGO_CADENA];
	if (openfilelote() == TRUE){
		printf("Ingrese el numero de vuelo (1000-1010) 0 para salir \n");
		scanf("%d", &vuelo);
		while (vuelo != 0)
		{
			if (vuelo <= 1010 && vuelo >= 1000)
			{
				printf("%s", setdestino(vuelo));		
				printf("Ingrese el nombre del pasajero: \n");
				memset(nombre,0x00,LARGO_CADENA);
				scanf("%s",nombre);
				fprintf(lote,"Vuelo: %d\nDestino: %s\nNombre: %s\n",vuelo,setdestino(vuelo),nombre);
				printf("Ingrese el numero de vuelo (1000-1010) 0 para salir \n");	
				scanf("%d", &vuelo);
			}
			else
			{
				printf("\nEl numero de vuelo ingresado no es valido\n");
				printf("Ingrese el numero de vuelo (1000-1010) 0 para salir \n");	
				scanf("%d", &vuelo);

			}
		}
	}
	fclose(lote);
}
void cargavuelorandom(int cantRandom){
	int vuelo = 0;
	char nombre[LARGO_CADENA];
	memset(nombre,0x00,LARGO_CADENA);
	if (openfilelote() == TRUE)
	{
		while (cantRandom > 0)
		{
			vuelo = 0;
			vuelo = createrandomparams(1000,1010);
			memset(nombre,'a',1);
			fprintf(lote,"Vuelo: %d\nDestino: %s\nNombre: %s\n",vuelo,setdestino(vuelo),nombre);
			cantRandom = cantRandom -1;			
		}
	}
	fclose(lote);
}



void setpasajeros(int pasajeros[CANTIDAD_VUELOS]){
	int i = 0,nrovuelo,contvuelo = 1000;

	char vuelo[LARGO_CADENA],nombredestino[LARGO_CADENA],nombre[LARGO_CADENA],destino[LARGO_CADENA];

	if(openfilelote() == TRUE)
	{
		while(!feof(lote))
		{
			memset(vuelo,0x00,LARGO_CADENA);
			memset(nombredestino,0x00,LARGO_CADENA);
			memset(nombre,0x00,LARGO_CADENA);
			memset(destino,0x00,LARGO_CADENA);
			memset(pasajeros, 0 ,CANTIDAD_VUELOS);
			fscanf(lote,"%s %d %s %s %s %s", vuelo,&nrovuelo,destino,nombredestino, nombre ,nombre);
			
			for (i=0;i<11;i++)
			{
				if (nrovuelo == contvuelo){
					pasajeros[i]+=1;
				}
				contvuelo +=1;
			}
			contvuelo = 1000;
		}
	}
	fclose(lote);

}


void generareservas(){
	char filename[LARGO_CADENA];
	int pasajeros[CANTIDAD_VUELOS], i= 0, nrovuelo= 1000;
	memset(pasajeros, 0 , CANTIDAD_VUELOS);
	if (readlote() == TRUE)
	{	
		memset(filename,0x00,LARGO_CADENA);
		sprintf(filename, "lote.%d.dat", nronuevolote);
		if (openfile(filename) == TRUE)
		{
			fprintf(lote2,"Vuelo    Destino    Pasajeros\n");
			setpasajeros(pasajeros);			
			for (i = 0; i< 11 ; i++)
			{
				
				fprintf(lote2,"%d    %s    %d\n",nrovuelo, setdestino(nrovuelo), *(pasajeros+i));
				nrovuelo+=1;
			}
		}
	fclose(lote2);			
	remove("lote.dat");
	}
	nronuevolote +=1;
}

