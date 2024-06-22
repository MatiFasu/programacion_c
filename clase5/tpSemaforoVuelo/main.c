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
	Vuelo vuelo;	int id_semaforo;
	
	FILE* cargas = NULL;

	id_semaforo =  creo_semaforo();
	inicia_semaforo(id_semaforo, VERDE);

	memset(vuelo.destino, 0x00, sizeof(vuelo.destino));
	memset(vuelo.nombre, 0x00, sizeof(vuelo.nombre));

	while(1)
	{
		
		do {
			printf("Ingrese nro vuelo: ");
			scanf("%d", &vuelo.v);
			
			if(vuelo.v == 0) break;

			while((vuelo.v<1000 || vuelo.v>1010)) {
				printf("Error - Ingrese nro vuelo: ");
				scanf("%d", &vuelo.v);
			}

			printf("Ingrese destino y nombre: ");
			scanf("%s %s", vuelo.destino, vuelo.nombre);

			espera_semaforo(id_semaforo);
			
				cargas = abrirArchivo(cargas, "lote.dat", "a");
				escribirArchivo(cargas, vuelo.v, vuelo.destino, vuelo.nombre);
				cerrarArchivo(cargas);

				printf("Se ingreso el vuelo %d \n", vuelo.v);
			
			levanta_semaforo(id_semaforo);
			usleep(INTERVALO_PARTIDA*1000);

		} while( vuelo.v != 0 );
		
	}

	printf("\n");	
	return 0;
}
