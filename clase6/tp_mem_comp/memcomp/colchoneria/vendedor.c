#include "stdio.h"
#include "stdlib.h"
#include "global.h"
#include "memcomp.h"
#include "funciones.h"
#include "semaforo.h"
#include "vendedor.h"


int main(int argc, char *argv[])
{
	int id_memoria = 0,id_semaforo = 0,idColchon = 0,cantSolicitada = 0;
	struct descripcion *stDescripcion;
	id_semaforo = creo_semaforo();
	stDescripcion = (descripcion*)creo_memoria(sizeof(descripcion)*5,&id_memoria);
	while (1)
	{
		printf("Ingrese el codigo de colchon del que vendera: \n");
		scanf("%d", &idColchon);
		if (idColchon < 6 && idColchon > 0)
		{
			printf("Ingrese la cantidad que quiere vender: \n");
			scanf("%d",&cantSolicitada);
			espera_semaforo(id_semaforo);
			if (stDescripcion[idColchon].cantidad > cantSolicitada)
			{
				stDescripcion[idColchon].cantidad = stDescripcion[idColchon].cantidad - cantSolicitada;
				printf("idColchon %d , nueva cantidad %d\n",idColchon, stDescripcion[idColchon].cantidad);
			}
			levanta_semaforo(id_semaforo);
		}
	}
	return 0;
}

