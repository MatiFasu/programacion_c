#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <pthread.h>

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

pthread_mutex_t mutex;

void *funcionThread (void *parametro)
{

	int i;
	printf("Hijo\n");
	for(i=0; i<10; i++) {
		pthread_mutex_lock(&mutex);
			printf("Soy el hijo y tengo mutex\n");
			sleep(1);
		pthread_mutex_unlock(&mutex);
	}

	printf("Soy el hijo y espero 10s\n");	
	sleep(10);
	printf("Hijo: termino\n");
	pthread_exit((void*)"Listo");
}

int main(int argc, char* argv[]) {
	
	    pthread_t idHilo;
	    pthread_attr_t atributos;
	    int i;
	    char *valorDevuelto = NULL;
	 
	    pthread_mutex_init(&mutex, NULL);

	    pthread_attr_init(&atributos);

	    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

	    if (pthread_create (&idHilo, &atributos, funcionThread, NULL) != 0)
	    {
		perror("No puedo crear thread");
		exit(-1);
	    } 
	    
	    for (i = 0; i < 10; i++)
	    {
		pthread_mutex_lock(&mutex);
		printf("Soy el padre y tengo el mutex\n");
		sleep(1);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	    }
	    printf("Padre : Espero al thread\n");

	    pthread_join(idHilo, (void **)&valorDevuelto);
	    printf("Padre : Ya ha terminado el thread\n");
	    printf("Padre : devuelve \"%s\"\n", valorDevuelto);

	printf("\n");
	return 0;
}
