#include "stdio.h"
#include "stdlib.h"
#include "global.h"
#include "memcomp.h"
#include "funciones.h"
#include "colchoneria.h"
#include "semaforo.h"

int main (int argc, char *argv[])
{
	int id_memoria = 0,id_semaforo = 0, i = 0;
	struct descripcion *stDescripcion; /*No lleva malloc pq le da el size en creo memoria*/
	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo , VERDE);
	stDescripcion = (descripcion*)creo_memoria(sizeof(descripcion)*5,&id_memoria);
	printf("Carga en memoria los valores default\n");
	for (i = 1; i < 6 ; i++)
	{
		stDescripcion[i].codigo = i;
		stDescripcion[i].cantidad = 10;
		strcpy(stDescripcion[i].nombre,getmarca(i));
		/*printf("Codigo: %d , Cantidad: %d, Marca: %s \n",stDescripcion[i].codigo,stDescripcion[i].cantidad,stDescripcion[i].nombre);*/
	}
	while (1){
		espera_semaforo(id_semaforo);
		for (i = 1; i < 6 ; i++)
		{
			if (stDescripcion[i].cantidad < 10)
			{
				printf("Se le suma un colchon a la marca %s nueva cantidad: %d\n",stDescripcion[i].nombre, stDescripcion[i].cantidad+1);
				stDescripcion[i].cantidad += 1;
			}
			muestraStock(stDescripcion,i);
		}	
		levanta_semaforo(id_semaforo);
		usleep(5000000);
	}
	
	return 0;
}

void muestraStock(struct descripcion *stDescripcion, int i)
{
	printf("Codigo: %d , Cantidad: %d, Marca: %s \n",stDescripcion[i].codigo,stDescripcion[i].cantidad,stDescripcion[i].nombre);

}
