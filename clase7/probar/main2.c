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

/*
Cola de mensajes -> esto si es una llamada entre procesos, no como los archivos (que sirven para escribir archivos) o memoria compartida (sirve para guardar variables)
La comunicacion es unidireccional
*/

#define DESDE 10
#define HASTA 20
#define INTERVALO 1

#define MSG_JOSE 		1
#define MSG_PEPITO		2

#define EVT_MENSAJE		1
#define EVT_FIN			2

int main(int argc, char* argv[]) {

	printf("main2");
			


	printf("\n");
	return 0;
}
