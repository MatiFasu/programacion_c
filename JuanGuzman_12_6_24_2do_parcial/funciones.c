#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "global.h"
#include "def.h"
#include "funciones.h"
#include "logger.h"

/*crear una structura e ingresar los datos que tomamos en el array definir una cadena de caracteres*/

int inDevolverAleatorio(int min, int max){
	int num=0;
	int random = 0;

 	random = rand();
  	num = random % ((max-min)+1) + min;
  	return num; 
}

int buscarElemento(int array[],int cantidad,int elemento){
	int i = 0;

	for(i=0; i<cantidad;i++){
		if(array[i] == elemento)
		{
			return 1;
		}
	}
	return 1;
}

void mostrarElemento(int flag,int num, int x){
	if(flag == 0)
	{
		printf("valor aleatorio N%d: %i\n",x,num);
	}
}

void agregarElemento(int arr[],int flag, int elemento, int longitud){
	if(flag == 0){
		arr[longitud] = elemento;
	}
}

void aumentarLimite(int flag,int *longitud){
	if(flag==0){
		(*longitud)++;
	}
}

int inValidarNum(int numero,int lowBound, int UpperBound){
	if(numero > lowBound -1 && numero < UpperBound +1) 
		return TRUE;
	
	return FALSE;
}



int existeVuelo(Vuelo arrayVuelos[], int nVuelo){
	int i;
	int contador = 0;

	for(i=0; i<9; i++){
		if(arrayVuelos[i].nVuelo == nVuelo){
			contador++;
		}
	}

	return contador;
}

int initArray(Vuelo arrayVuelos[]){
	int i;

	for(i=0; i<9; i++){
		
		arrayVuelos[i].nVuelo = 0;
		strncpy(arrayVuelos[i].destino," ",sizeof(arrayVuelos[i].destino)-1);
		arrayVuelos[i].pasajeros = 0;
	}
	return 1;
}

void mostrarArray(Vuelo arrayVuelos[]){
	int i;
	printf("VUELO    DESTINO    CANTIDAD\n");
	for(i=0; i<9; i++){
		if(arrayVuelos[i].nVuelo != 0){
			printf("%d    %s    %d\n",arrayVuelos[i].nVuelo,arrayVuelos[i].destino,arrayVuelos[i].pasajeros);
		}
	}
}

void initReporte(Reporte r[]){
	int i;

	for(i = 0;i < 4; i++){
		printf("INIT ARRAY REPORTE - POS[%d]\n\n",i);
		r[i].cantOpUno = 0;
		r[i].cantOpCero = 0;
		r[i].importeTotalEfec = 0;
		r[i].importeTotalCheq = 0;
		printf("TC-EFEC: %d\n",r[i].cantOpUno);
		printf("T$-EFEC: $%d\n",r[i].importeTotalEfec);
		printf("TC-CHEQ: %d\n",r[i].cantOpCero);
		printf("TC$-CHEQ: $%d\n\n",r[i].importeTotalCheq);
	}
}


void actualizarReporte(Reporte r[],int importe, int op,int idFile){
	if(op == 1){
		r[idFile].cantOpUno = r[idFile].cantOpUno + 1;
		r[idFile].importeTotalEfec = r[idFile].importeTotalEfec + importe;

		/*ACTUALIZO REPORTE TOTAL*/
		r[0].cantOpUno = r[0].cantOpUno + 1;
		r[0].importeTotalEfec = r[0].importeTotalEfec + importe;
	}
	if(op == 0){
		r[idFile].cantOpCero = r[idFile].cantOpCero + 1;	
		r[idFile].importeTotalCheq = r[idFile].importeTotalCheq + importe;
		
		/*ACTUALIZO REPORTE TOTAL*/
		r[0].cantOpCero = r[0].cantOpCero + 1;
		r[0].importeTotalCheq = r[0].importeTotalCheq + importe;		
	}
}

void mostrarReporte(Reporte r[], int idFile){

	if(idFile == 0) /*TOTAL*/
		 printf("TOTAL\n");
	if(idFile == 1) /*CAJ 1*/
		 printf("CAJERO 1\n");
	if(idFile == 2) /*CAJ 2*/
		 printf("CAJERO 2\n");
	if(idFile == 3) /*CAJ 3*/
		 printf("CAJERO 3\n");

	printf("TC-EFEC: %d\n",r[idFile].cantOpUno);
	printf("T$-EFEC: $%d\n",r[idFile].importeTotalEfec);
	printf("TC-CHEQ: %d\n",r[idFile].cantOpCero);
	printf("TC$-CHEQ: $%d\n\n",r[idFile].importeTotalCheq);
}


void initPaneles(Panel p[]){
	int i;

	
	for(i = 0; i < 3; i++){
		printf("INIT ARRAY PANEL - POS[%d]\n",i);
		p[i].id = i;
		memset(p[i].mensaje,0x00,sizeof(p[i].mensaje));
		strncpy(p[i].mensaje,"DEFAULT", sizeof(p[i].mensaje) - 1);
		printf("ID - %d\n",i);
		printf("MENSAJE - %s\n",p[i].mensaje);
	}
}

void actualizarPanel(Panel p[],int idPanel,char *mensaje){
	strncpy(p[idPanel].mensaje,mensaje, sizeof(p[idPanel].mensaje) - 1);
}

void funcion(int a, int b, int (*scope)(int,int)){
	int result = 0;
	result = scope(a,b);

	printf("result %d\n",result);
}

int sumar(int a,int b){
	int result = 0;
	result = a + b;
	return result;
}

int restar(int a,int b){
	int result = 0;
	result = a - b;
	return result;
}

void initArrayN(int n[], int cant){
	int i;
	for(i = 0; i<cant; i ++){
		n[i] = 0;
	}
}

int verificarArray(int n[], int cant,int e){
	int i;
	int result = 0;
	for(i = 0; i<cant; i ++){
		if(n[i] == e){
			result = 1;
			i = cant;
		}
	}
	return result;
}

int recGenerarNumeroUnico(int n[],int t,int min,int max){
	int result = 0;
	int flag = 0;

	result = inDevolverAleatorio(min,max);
	flag = verificarArray(n,t,result);
	if(flag == 1)return recGenerarNumeroUnico(n,t,min,max);

	else return result;
}

void initSession(Session *s){
	int pos = 0;
	s[pos].idJugador = 0;
	s[pos].bolilla = 0;
}

int ContarElementoCarton(int c[][3],int e){
	int numCounter = 0;
	int i;
	int j;

	for(i=0;i<I;i++){
		for(j=0;j<J;j++) if(c[i][j] == e)numCounter++;
	}
			
	return numCounter;
}

int recGenerarNumeroUnicoEnCarton(int n[][3],int min,int max){
	int result = 0;
	int counter = 0;

	result = inDevolverAleatorio(min,max);
	counter = ContarElementoCarton(n,result);

	if(counter > 1) return recGenerarNumeroUnicoEnCarton(n,min,max);
	return result;
}

void initCarton(int c[][3],int min, int max,int id){
	int element = 0;
	int i;
	int j;

	for(i=0;i<I;i++){
		for(j=0;j<J;j++){
			element = recGenerarNumeroUnicoEnCarton(c,min,max);
			c[i][j] = element;
		}
	}
	mostrarArrayCarton(c,id);
}

void initArrayBingo(int c[],int size,int min, int max,int debug){
	int i;

	for(i=0;i<size;i++){
		c[i] = recGenerarNumeroUnico(c,size,min,max);
	}
	if(debug == DEBUG_ON){
		showBegin(debug);
		for(i=0;i<size;i++){
			printf("E[%d] ",c[i]);
		}
		printf("\n");
		showEnd(debug);
	}
}

void mostrarArrayCarton(int c[][3],int id){
	int i;
	int j;

	printf("------------------------------\n");
	printf("CARTON JUGADOR %d\n\n",id);
	for(i=0;i<I;i++){
		for(j=0;j<J;j++){
			printf("[%d][%d] = %d\n",i,j,c[i][j]);
		}
	}
	printf("------------------------------\n\n");	
}

void mostrarBolillas(int a[],int t){
	int i;
	printf("------------------------------\n");
	printf("          Bolillas\n");
	for(i=0;i<t;i++){
		if(a[i] == -1)i = t;
		else printf("B[%d]: %d\n",i,a[i]); 
	}
	printf("------------------------------\n");
}

void initBolillas(int a[],int t){
	int i;

	for(i=0;i<t;i++){
		a[i] = -1; 
	}
	for(i=0;i<t;i++){
		printf("B[%d]: %d\n",i,a[i]); 
	}
}

int recSumar(int num){
	if(num == 0)
		return 0;
	else 
		return num + recSumar(num-1);

}


void initAnimales(Animal a[],int size){
	int i;

	for (i = 0; i < size; i++){
		a[i].id = i;
		a[i].players = 3;
		a[i].tries = 0;
		a[i].position = 0;
		memset(a[i].nombre,0x00,sizeof(a[i].nombre));
	}

}


	



	






