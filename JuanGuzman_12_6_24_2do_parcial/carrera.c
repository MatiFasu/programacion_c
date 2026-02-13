#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "unistd.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "pthread.h"
#include "def.h"
#include "global.h"
#include "funciones.h"
#include "colaMensajeria.h"
#include "threadAnimal.h"
#include "memoria.h"
#include "logger.h"


int main(int arc, char *argc[]){
	int debug = DEBUG_ON;
	int idQueue = 0;
	int i;
	int players = 3;
	int idMemoria = 0;
	int pos = 0;

	CarreraSession *memoria = NULL; 
	pthread_t *idHilo;
	pthread_attr_t atributos;
	Animal *animal;

	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_JOINABLE);
	pthread_mutex_init(&mutex,NULL);

	idHilo = (pthread_t*)malloc(sizeof(pthread_t)*players);
	animal = (Animal*)malloc(sizeof(Animal)*players);
	memoria = (CarreraSession*)creoMemoria(sizeof(CarreraSession)*1,&idMemoria);
	memoria[pos].allReady = 0;
	memoria[pos].start = 0;

	showBegin(debug);
	showStrIntLog("LLAMANDO JUGADORES ",players,debug);
	showEnd(debug);

	srand(time(NULL));

	for(i= 0; i<players;i++){
		animal[i].id = i;
		animal[i].idQueue = idQueue;
		animal[i].players = players;
		animal[i].tries = 0;
		animal[i].position = 0;

		memset(animal[i].nombre,0x00,sizeof(animal[i].nombre));

		if( i == 0){
			animal[i].minPasos = 4;
			animal[i].maxPasos = 9;
			strncpy(animal[i].nombre,"CONEJO",sizeof(animal[i].nombre)-1);
		}
		if( i == 1){
			animal[i].minPasos = 1;
			animal[i].maxPasos = 10;
			strncpy(animal[i].nombre,"GATO",sizeof(animal[i].nombre)-1);
		}
		if( i == 2){
			animal[i].minPasos = 3;
			animal[i].maxPasos = 8;
			strncpy(animal[i].nombre,"PERRO",sizeof(animal[i].nombre)-1);
		}
		pthread_create (&idHilo[i],&atributos,funcionThreadAnimal,&animal[i]);
	}

	showBegin(debug);
	for(i= 0; i<players;i++){
		pthread_join(idHilo[i],NULL);
		showStrIntLog("TERMINO PROCESO JUGADOR ",animal[i].id,debug);
	}
	showEnd(debug);

	for(i= 0; i<players;i++){
		showBegin(debug);
		showStrIntLog("ID ANIMAL ",animal[i].id,debug);
		showStrIntLog("RECORRIDO ",animal[i].position,debug);
		showStrIntLog("VUELTAS ",animal[i].tries,debug);
		showEnd(debug);
	}
	free(idHilo);
	shmdt((char *)memoria);
	shmctl(idMemoria,IPC_RMID,(struct shmid_ds *)NULL);
	return 0;
}
