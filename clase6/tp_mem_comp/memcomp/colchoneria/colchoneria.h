#ifndef _colchoneria
#define _colchoneria

typedef struct descripcion
{
	int codigo;
	int cantidad;
	char nombre[LARGO_CADENA];
}descripcion;

void muestraStock(struct descripcion *stDescripcion, int i);
#endif
