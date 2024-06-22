#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <def.h>
#include <funciones.h>
#include <semaforo.h>
#include <archivos.h>
#include <global.h>

int main(int arg, char *argv[])
{
	Vuelo vuelo;
	int id_semaforo;
	int cant_producto = 0, i = 1;
	FILE *consumidor = NULL; 
	char filename[20];
	
	
	id_semaforo =  creo_semaforo();
	
	while(1)
	{
		espera_semaforo(id_semaforo);
			
			consumidor = fopen("lote.dat", "r");
		
			if (consumidor!=NULL)
			{
				printf("\nCONSUMIMOS\n");
				while (!feof(consumidor))
				{
					fscanf(consumidor,"%d %s %s", &vuelo.v, vuelo.destino, vuelo.nombre);
					printf("%d %s %s\n", vuelo.v, vuelo.destino, vuelo.nombre);
					usleep(INTERVALO_PRODUCTO*1000);
					cant_producto++;
				}
				fclose(consumidor);
				if(cant_producto>0)
				{
					/*renombrar archivo*/
					sprintf(filename, "lote.%03d.dat", i);		
					rename("lote.dat", filename);

					i++;
				}
 
			}
			else
				printf("Error al abrir lote.dat");
						
		levanta_semaforo(id_semaforo);
		usleep(INTERVALO_PARTIDA*1000);
	};



	printf("\n");	
	return 0;
}
