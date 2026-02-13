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
#include "threadBolillero.h"
#include "memoria.h"
#include "logger.h"



int main(int arc, char *argc[]){
	int debug = DEBUG_ON;
	int idQueue = 0;
	int players = 0;
	int i;
	int idMemoria = 0;
	int pos = 0;
	
	BingoSession *memoria = NULL; 
	pthread_t *idHilo;
	pthread_attr_t atributos;

	Bolillero *bolillero; 

	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_JOINABLE);

	idHilo = (pthread_t*)malloc(sizeof(pthread_t)*1);
	bolillero = (Bolillero*)malloc(sizeof(Bolillero)*1);
	memoria = (BingoSession*)creoMemoria(sizeof(BingoSession)*1,&idMemoria);
	memoria[pos].start = 0;

	players = atoi(argc[1]);

	showBegin(debug);
	showStrIntLog("JUGADORES DE BINGO ",players,debug);
	showEnd(debug);

	idQueue = creoColaMensajes();
	borrarMensajes(idQueue);

	for(i= 0; i<1;i++){
		bolillero[i].idQueue = idQueue;
		bolillero[i].players = players;
		pthread_create (&idHilo[i],&atributos,funcionThreadBolillero,&bolillero[i]);
	}

	for(i= 0; i<1;i++){
		pthread_join(idHilo[i],NULL);
		showStrLog("PROCESO BOLILLERO TERMINADO",debug);
	}
	shmdt((char *)memoria);
	shmctl(idMemoria,IPC_RMID,(struct shmid_ds *)NULL);
	free(idHilo);
	return 0;
}
