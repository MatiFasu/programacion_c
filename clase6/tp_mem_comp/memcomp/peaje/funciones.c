#include "stdio.h"
#include "stdlib.h"
#include "funciones.h"
#include "global.h"
#include "string.h"
#include "time.h"

int createrandom()
{
	int num=0,min=0,max=0;
	printf("Ingrese el minimo: \n");
	scanf("%d",&min);
	printf("Ingrese el maximo: \n");
	scanf("%d",&max);
	srand(time(0));
	num = (rand() % (min - max + 1)) + min;

	return num;
}
int createrandomparams(int desde, int hasta)
{
	int num = 0;
	srand(time(0));
	num = (rand() % (desde - hasta + 1)) + desde;
	return num;

}
int getmin(int old,int new){
	if (old > new)
	{
		return new;
	}
	return old;
}


