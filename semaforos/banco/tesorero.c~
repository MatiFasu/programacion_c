#include "stdlib.h"
#include "stdio.h"
#include "gestorArchivos.h"
#include "funciones.h"
#include "global.h"
#include "string.h"
#include "semaforo.h"
#include "tesorero.h"
FILE *archivo;
FILE *tesorero;

int main (int argc, char const *argv[])
{
	int optmenu = 0,id_semaforo;
	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo,VERDE);
	while (optmenu != -1)
	{
		printf("Ingrese una opcion: \n");
		printf("1 Iniciar tesorero\n");
		printf("2 Loop to hell\n");
		printf("-1 Salir\n");
		scanf("%d",&optmenu);
		switch(optmenu)
		{
			case 1:
				espera_semaforo(id_semaforo);
				generatesorero();
				levanta_semaforo(id_semaforo);
				break;
			case 2:
				while (1){
					espera_semaforo(id_semaforo);
					usleep(500000);
					generatesorero();
					levanta_semaforo(id_semaforo);
					usleep(500000);
				}
				break;
			case -1:
				printf("\nBye!\n");
				break;
			default:
				printf("%d no es una opcion valida\n", optmenu);
				break;
		} 
	
	}

	return 0;
}


void generatesorero()
{
	struct totalcajero cajero ={0,0,0,0},total ={0,0,0,0};
	char filename[LARGO_CADENA];
	int i = 0;
	memset(filename,0x00,sizeof(filename));
	strcpy(filename,"tesorero.dat");
	if (openfiletesorero(filename)==TRUE)
	{
		total = sumacajeros(gettotal(1),gettotal(2),gettotal(3));
		fprintf(tesorero,"TOTAL: \n TC-EFECT T$-EFECT TC-CHEQ T$-CHEQ\n %d %d %d %d\n\n",total.tefectivo,total.cantefectivo,total.tcheque,total.cantcheque);
		for (i = 1; i < 4; i++)
		{
			cajero = gettotal(i);
			fprintf(tesorero,"CAJERO%d: \n TC-EFECT T$-EFECT TC-CHEQ T$-CHEQ\n %d %d %d %d \n\n",i,cajero.tefectivo,cajero.cantefectivo,cajero.tcheque,cajero.cantcheque);
		}

	}
	fclose(tesorero);

}

struct totalcajero gettotal(int nrocajero)
{
	struct totalcajero cajero ={0,0,0,0};
	int monto=0,tipo=0;	
	char filename[LARGO_CADENA];
	memset(filename,0x00,sizeof(filename));
	sprintf(filename,"cajero%d.dat",nrocajero);
	if (openfile(filename)==TRUE){
		while (!feof(archivo))
		{
			fscanf(archivo, "%d %d" , &monto, &tipo);
			if (tipo == 0)
				{
				cajero.tefectivo +=1;
				cajero.cantefectivo += monto;
				}
			if (tipo == 1)
				{
				cajero.tcheque+=1;
				cajero.cantcheque+=monto;
				}
		}
		fclose(archivo);
		/*remove(filename);*/
	}
	return cajero;
}

struct totalcajero sumacajeros(struct totalcajero cajero1,struct totalcajero cajero2,struct totalcajero cajero3)
{
	struct totalcajero total ={0,0,0,0};
	total.tefectivo = cajero1.tefectivo + cajero2.tefectivo + cajero3.tefectivo;
	total.cantefectivo = cajero1.cantefectivo + cajero2.cantefectivo + cajero3.cantefectivo;
	total.tcheque = cajero1.tcheque + cajero2.tcheque + cajero3.tcheque;
	total.cantcheque = cajero1.cantcheque + cajero2.cantcheque + cajero3.cantcheque;
	
	return total;

}

