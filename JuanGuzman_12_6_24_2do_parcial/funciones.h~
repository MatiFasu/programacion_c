#ifndef _FUNCIONES
#define _FUNCIONES
#include "global.h"

/*RANDOM*/
int inDevolverAleatorio(int min, int max);
int buscarElemento(int array[],int cantidad,int elemento);
void mostrarElemento(int flag,int num, int x);
void agregarElemento(int arr[],int flag, int elemento, int longitud);
void aumentarLimite(int flag,int *longitud);

/*VUELO*/
int inValidarNum(int numero,int lowBound, int UpperBound);
int existeVuelo(Vuelo arrayVuelos[], int nVuelo);
int initArray(Vuelo arrayVuelos[]);
void mostrarArray(Vuelo arrayVuelos[]);

/*CAJERO*/
void initReporte(Reporte r[]);
void actualizarReporte(Reporte r[],int importe, int op,int idFile);
void mostrarReporte(Reporte r[], int idFile);

/*PANELCCI*/
void initPaneles(Panel p[]);
void actualizarPanel(Panel p[],int idPanel,char *mensaje);

/*CALLBACKS*/
void funcion(int a, int b, int (*scope)(int,int));
int sumar(int a,int b);
int restar(int a,int b);
void initArrayN(int n[],int cant);
int verificarArray(int n[], int cant,int e);
int recGenerarNumeroUnico(int n[],int t,int min,int max);

/*BINGO*/
void initSession(Session *s);
int ContarElementoCarton(int c[I][J],int e);
int recGenerarNumeroUnicoEnCarton(int n[I][J],int min,int max);
void initCarton(int c[I][J],int min, int max,int id);
void mostrarArrayCarton(int c[][3],int id);
void mostrarBolillas(int a[],int t);
void initBolillas(int a[],int t);
void initArrayBingo(int c[],int size,int min, int max,int debug);

int recSumar(int num);

void initAnimales(Animal a[],int size);
#endif

