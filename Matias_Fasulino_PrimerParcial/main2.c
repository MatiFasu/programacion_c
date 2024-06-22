#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <def.h>
#include <archivos.h>
#include <global.h>
#include <clave.h>
#include <semaforo.h>


int main(int argc, char* argv[]) {

	int id_semaforo, i;

	char nombreArchivo[20];

	FILE* archivo = NULL;

	id_semaforo = creo_semaforo();

	while(1)
	{

		for(i=0; i<2; i++) 
		{	
			sprintf(nombreArchivo, "equipo%d.dat", i+1);			

			system("clear");
			
			espera_semaforo(id_semaforo);
				
			archivo = abrirArchivo(archivo, nombreArchivo, "r");	

			leerArchivo(archivo);					

			cerrarArchivo(archivo);			
			
			printf("\n");

			sleep(1);
			levanta_semaforo(id_semaforo);
			sleep(3);
		}
	}


	printf("\n");
	return 0;
}
