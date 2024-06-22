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

	int id_semaforo;
	
	int cant=0, cant2=0;

	char nombreArchivo[20];

	FILE* archivo = NULL;

	int tipo_alum = atoi(argv[1]);	
		
	if(argc != 2) {
		printf("Error - Ingrese tipo de alumno a procesar: 1 o 2");
		return 1;
	}

	sprintf(nombreArchivo, "alumnos%d.dat", tipo_alum);

	id_semaforo = creo_semaforo();

	while(1)
	{

		espera_semaforo(id_semaforo);
		
		if( abrirArchivo(archivo, nombreArchivo, "r")==NULL ) {
			levanta_semaforo(id_semaforo);
		} else {
			
			cant2 = getCant(archivo);

			if(cant2 > cant) 
			{
				rewind(archivo);

				system("clear");

				leerArchivo(archivo);
			}			
			
			cerrarArchivo(archivo);
			levanta_semaforo(id_semaforo);	
		}	
	
		sleep(15);	

	}

	printf("\n");
	return 0;
}
