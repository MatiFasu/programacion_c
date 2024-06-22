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




int main()
{
	char cadena[LARGO]; /* Un array lo suficientemente grande como para guardar la línea más larga del fichero */
	int cant_producto=0;
	FILE *consumidor; 
	
	int id_semaforo;
	id_semaforo =  creo_semaforo();
	
	while(1)
	{
		espera_semaforo(id_semaforo);
			
			consumidor = fopen("producto.txt", "r");
			if (consumidor!=NULL)
			{
				printf("\nCONSUMIMOS\n");
				while (!feof(consumidor))
				{
					fscanf(consumidor,"%s",cadena);
					printf("%s\n", cadena);
					usleep(INTERVALO_PRODUCTO*1000);
					cant_producto++;
				}
				fclose(consumidor);
				if(cant_producto>0)
				{
					printf("\nBORRAMOS\n");
					remove("producto.txt");
					cant_producto=0;
				}
			}
			else
				perror ("Error al abrir producto.txt");
			printf("\nESPERAMOS\n");
						
		levanta_semaforo(id_semaforo);
		usleep(INTERVALO_PARTIDA*1000);
	};
	return 0;
}
