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
#include "threadJugador.h"
#include "memoria.h"
#include "logger.h"

/*INICIA SEGUNDO*/

int main(int arc, char *argc[]){
	int debug = DEBUG_ON;
	int idQueue = 0;
	int i;
	int players = 0;
	int idMemoria = 0;
	int pos = 0;

	BingoSession *memoria = NULL; 
	pthread_t *idHilo;
	pthread_attr_t atributos;
	GamePlayer *player;
	

	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_JOINABLE);
	pthread_mutex_init(&mutex,NULL);

	idHilo = (pthread_t*)malloc(sizeof(pthread_t)*players);
	player = (GamePlayer*)malloc(sizeof(GamePlayer)*players);
	memoria = (BingoSession*)creoMemoria(sizeof(BingoSession)*1,&idMemoria);
	memoria[pos].allReady = 0;
	memoria[pos].start = 0;

	players = atoi(argc[1]);

	showBegin(debug);
	showStrIntLog("LLAMANDO JUGADORES ",players,debug);
	showEnd(debug);

	srand(time(NULL));

	for(i= 0; i<players;i++){
		player[i].idPlayer = i;
		player[i].idQueue = idQueue;
		player[i].players = players;
		player[i].aciertos = 0;
		pthread_create (&idHilo[i],&atributos,funcionThreadPlayer,&player[i]);
	}

	showBegin(debug);
	for(i= 0; i<players;i++){
		pthread_join(idHilo[i],NULL);
		showStrIntLog("TERMINO PROCESO JUGADOR ",player[i].idPlayer,debug);
		
	}
	showEnd(debug);

	for(i= 0; i<players;i++){
		showBegin(debug);
		showStrIntLog("ID JUGADOR ",player[i].idPlayer,debug);
		showStrIntLog("ACIERTOS ",player[i].aciertos,debug);
		showEnd(debug);
	}
	free(idHilo);
	return 0;
}
