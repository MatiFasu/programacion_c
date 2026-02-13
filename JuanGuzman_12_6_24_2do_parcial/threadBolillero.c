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
#include "threadBolillero.h"
#include "colaMensajeria.h"
#include "logger.h"

void *funcionThreadBolillero(void *param){
	int debug = DEBUG_ON;
	int key = RUN;
	
	int idMemoria = 0;
	int idQueue = 0;
	int players = 0;

	int idSender = 0;
	int idReceiver = 0;

	int num = 0;
	int pos = 0;
	int memoryBase = 0;
	int i;
	int waitTime = 0;
	int allReady = 0;

	int arraySize = MAX;
	int bolillas[MAX];

	char message[LARGO_MENSAJE];
	
	BingoSession *memoria = NULL; 
	Bolillero *bolillero = (Bolillero*) param;
	Mensaje msg;
	
	memset(message,0x00,sizeof(message));

	memoria = (BingoSession*)creoMemoria(sizeof(BingoSession)*1,&idMemoria);
	
	idQueue = bolillero->idQueue;
	players = bolillero->players;

	srand(time(NULL));

	initArrayN(bolillas,arraySize);
	
	idSender = MSG_BINGO;
	
	idQueue = creoColaMensajes();	
	borrarMensajes(idQueue);

	while(key == RUN){
		sleep(1);
		allReady = memoria[memoryBase].allReady;

		showBegin(debug);
		if(allReady < players)
			showStrIntLog("ESPERANDO JUGADORES DISPONIBLES ",allReady,debug);

		else if(allReady == players){
			memoria[memoryBase].start = 1;
			showStrIntLog("COMENZO EL BINGO - JUGADORES: ",allReady,debug);
			key = STOP;
		}
		showEnd(debug);
	}
	
	sleep(2);

	key = RUN;

	while(key == RUN)
	{
		waitTime = inDevolverAleatorio(1,5);
		sleep(waitTime);

		if(pos<arraySize){
			showBegin(debug);
			num = recGenerarNumeroUnico(bolillas,arraySize,MIN,MAX);
			bolillas[pos] = num;
			pos++;

			memset(message,0x00,sizeof(message));
			sprintf(message,"%d",num);
			showStrStrLog("NUEVA BOLILLA",message,debug);

			for(i = 0;i<players;i++){
				idReceiver = 0;
				idReceiver = MSG_PLAYER + i;

				enviarMensaje(idQueue,idReceiver,idSender,EVT_BOLILLA,message);
			}

			for(i = 0;i<players;i++){
			
				recibirMensaje(idQueue,idSender,&msg);

				switch(msg.intEvent){
		
					case EVT_CARTONLLENO: 
						key = STOP;
						i = players;
						showStrIntLog("BOLILLERO ENCONTRO GANADOR ",
							      msg.intSender,
							      debug);
						showEnd(debug);
						break;

					case EVT_NONE:
						break;
				}
			}

			showEnd(debug);
		}		
	}
	return NULL;
}
