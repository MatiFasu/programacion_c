#include "stdio.h"
#include "stdlib.h"
#include "funciones.h"
#include "global.h"
#include "string.h"


int createrandom()
{
	int num=0,min=0,max=0;
	printf("Ingrese el minimo: \n");
	scanf("%d",&min);
	printf("Ingrese el maximo: \n");
	scanf("%d",&max);
	srand(rand());
	num = (rand() % (min - max + 1)) + min;

	return num;
}
int createrandomparams(int desde, int hasta)
{
	int num = 0;
	srand(rand());
	num = (rand() % (desde - hasta + 1)) + desde;
	return num;

}


char *setdestino (int nrovuelo){
	if (nrovuelo == 1000){
		return "LAX";
	}
	else if(nrovuelo == 1001){
		return "EZE";			
	}
	else if(nrovuelo == 1002){
		return "JFK";			
	}
	else if(nrovuelo == 1003){
		return "BRC";			
	}
	else if(nrovuelo == 1004){
		return "CRD";			
	}
	else if(nrovuelo == 1005){
		return "MIA";			
	}
	else if(nrovuelo == 1006){
		return "MDP";			
	}
	else if(nrovuelo == 1007){
		return "TEX";			
	}
	else if(nrovuelo == 1008){
		return "HUD";			
	}
	else if(nrovuelo == 1009){
		return "LND";			
	}
	else if(nrovuelo == 1010){
		return "MDR";			
	}else
		return "ERR";
}




