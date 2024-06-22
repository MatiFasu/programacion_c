#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <def.h>
#include <archivos.h>
#include <global.h>
#include <clave.h>
#include <semaforo.h>
#include <memoria.h>
#include <cola.h>

void funcion(int valor1, int valor2)
{
	printf("\nValor 1: %d", valor1);
	printf("\nValor 2: %d\n", valor2);
}

int sumar(int a, int b)
{
	return a+b;
}

int restar(int a, int b)
{
	return a-b;
}

void funcion_principal(int a, int b, int (*funcion)(int, int))
{
	int resultado = funcion(a,b);
	printf("El resultado es: %d", resultado);
}

/*
	quiero q los proveedores de android corra en todos esos disp. (nokia, samsung, etc) y esos disp tienen problemas. Tengo q dar soporte a cada uno de ellos? No, uso callbacks. Le digo a la empresa: te doy el nombre o los parametros que tiene que usar. El los implementa y da un resultado.
	Cada var mutex no se comparte entre procesos.
	void puntero -> a mi me interesa la direccion de memoria.
*/

int main(int argc, char* argv[]) {
	
	void (*puntero_funcion)(int, int) = &funcion;

	puntero_funcion(2,5);

	int num1 = 5;
	int num2 = 4;

	printf("\nSuma\n");
	funcion_principal(num1, num2, sumar);

	printf("\nResta\n");
	funcion_principal(num1, num2, resta);

	printf("\n");
	return 0;
}
