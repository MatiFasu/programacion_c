#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "unistd.h"

#include "sys/ipc.h"
#include "sys/shm.h"
#include "pthread.h"

#include "global.h"
#include "funciones.h"
#include "memoria.h"
#include "def.h"
#include "threadJugador.h"
#include "colaMensajeria.h"
#include "logger.h"

void *funcionThreadPlayer(void *param){
	int debug = DEBUG_ON;
	int key = RUN;
	int firstLap = 0;

	int idPlayer = 0;
	int idQueue = 0;
	int players = 0;
	int carton[5];
	int aciertos = 0;
	int start = 0;

	int idMemoria = 0;
	int bolilla = 0;
	int sizeCarton = 5;
	int tengoBolilla = 0;

	int idSender = 0;
	long rteId = 0;
	int allReady = 0;
	int idGanador = 0;
	int idReceiver = 0;

	int i;
	int pos = 0;
	
	Mensaje msg;
	GamePlayer *player = (GamePlayer*) param;
	BingoSession *memoria = NULL;
	
	memoria = (BingoSession*)creoMemoria(sizeof(BingoSession)*1,&idMemoria);

	idPlayer = player->idPlayer;
	idQueue = player->idQueue;
	players = player->players;

	idSender = MSG_PLAYER+idPlayer;

	initArrayBingo(carton,sizeCarton,MIN,MAX,debug);

	idQueue = creoColaMensajes();
	borrarMensajes(idQueue);

	while(key == RUN){

		sleep(1);
		pthread_mutex_lock(&mutex);
		sleep(1);

		allReady = memoria[pos].allReady;
		start = memoria[pos].start;

		showBegin(debug);
		if(allReady == players && start == 1){
			key = STOP;
			showStrIntLog("PLAYER ",idPlayer,debug);
			showStrIntLog("LISTOS TODOS ",allReady,debug);
		}
		else{
			showStrIntLog("PLAYER ",idPlayer,debug);
			showStrIntLog("ESPERANDO HILOS HERMANOS ",allReady,debug);
		}
		showEnd(debug);

		if(firstLap == 0){
			memoria[pos].allReady ++;
			firstLap = 1;
		}

		sleep(1);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}

	key = RUN;

	while(key == RUN)
	{
		sleep(1);
		pthread_mutex_lock(&mutex);
		sleep(1);

		showBegin(debug);
		showStrIntLog("ID JUGADOR ",idPlayer,debug);

		recibirMensaje(idQueue,idSender,&msg);
		
		switch(msg.intEvent)
		{
			
			case EVT_CARTONLLENO:
				key = STOP;
				idGanador = msg.intSender;

				if(idGanador == idSender)showStrIntLog("BINGOOOO",idSender,debug);
				else showStrIntLog("CANTO BINGO EL JUGADOR",idGanador,debug);

				showEnd(debug);

				break;
			
			case EVT_BOLILLA:
				bolilla = atoi(msg.charMensaje);
				tengoBolilla = verificarArray(carton,sizeCarton,bolilla);

				if(tengoBolilla == 1){
					aciertos++;
					showStrIntLog("TENGO LA BOLILLA ",bolilla,debug);
					showStrIntLog("ACIERTOS ",aciertos,debug);
				}
				else{
					showStrIntLog("NO TENGO EL NUMERO ",bolilla,debug);
					showStrIntLog("ACIERTOS ",aciertos,debug);
				}

				if(aciertos == sizeCarton){
					for(i = 0;i<players+1;i++){
						if(i == players) idReceiver = MSG_BINGO;
						else idReceiver = MSG_PLAYER + i;

						enviarMensaje(idQueue,
							      idReceiver,
							      idSender,
							      EVT_CARTONLLENO,
							      " ");

						showStrIntLog("ENVIE MENSAJE A ",idReceiver,debug);
					}
				}
				else{
					enviarMensaje(idQueue,MSG_BINGO,idSender,EVT_NONE," ");
					showStrLog("ENVIE MENSAJE A BINGO",debug);
				}
				showEnd(debug);

				break;
			
			default:
				showStrLongLog("EVENTO SIN DEFINIR DE SENDER ",rteId,debug);
				showEnd(debug);
				break;
							
		}

		sleep(1);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	player->aciertos = aciertos;	
	return NULL;
}
