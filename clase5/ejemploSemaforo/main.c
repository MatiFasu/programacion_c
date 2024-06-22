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
	int nro_producto=0, nro_partida=0;
	FILE *productor; 

	
	int id_semaforo;
	
	id_semaforo =  creo_semaforo();
	inicia_semaforo(id_semaforo, VERDE);
	
	while(1)
	{
		espera_semaforo(id_semaforo);
			
			printf("\nPRODUCIMOS-PARTIDA-%04d\n",nro_partida);
			productor = fopen("producto.txt", "a");
			if (productor!=NULL)
			{
				for (nro_producto=0; nro_producto<CANTIDAD_PARTIDA; nro_producto++)
				{
					sprintf(cadena, "PRODUCTO-%04d-%04d\n", nro_partida, nro_producto);
					printf("%s", cadena);
					fprintf(productor,"%s",cadena);
					usleep(INTERVALO_PRODUCTO*1000);
				}
				fclose(productor);
				nro_partida++;
				printf("\nESPERAMOS\n");
			}
			else
			{
				perror ("Error al abrir producto.txt");
			}
			
		levanta_semaforo(id_semaforo);
		usleep(INTERVALO_PARTIDA*1000);
	};

	printf("\n");
	return 0;
}
