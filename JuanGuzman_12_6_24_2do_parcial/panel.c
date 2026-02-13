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
#include "logger.h"
#include "memoria.h"
#include "colaMensajeria.h"

int main(int arc, char *argc[]){
	int debug = DEBUG_ON;
	int key = RUN;	

	int idQueue = 0;
	int idMemoria = 0;

	int i;
	char nombreAnimal[30];
	int idAnimal = 0;
	int logicSender = 0;
	int allReady = 0;
	int partiesInvolved = 3;
	int idOutput = 0;
	int pos = 0;
	int cont = 0;
	int idWinning = 0;
	int idReceiver = 0;
	int limit = 30;
	int max = 0;

	char mensaje[LARGO_MENSAJE];

	Mensaje msg;
	CarreraSession *memoria = NULL;
	Animal animal[3];

	memset(nombreAnimal,0x00,sizeof(nombreAnimal));
	memset(mensaje,0x00,sizeof(mensaje));

	memoria = (CarreraSession*)creoMemoria(sizeof(CarreraSession)*1,&idMemoria);
	memoria[pos].allReady = 0;
	memoria[pos].start = 0;
	
	showBegin(debug);
	showStrLog("PANEL ENCENDIDO",debug);
	showEnd(debug);

	
	initAnimales(animal,3);
	idQueue = creoColaMensajes();
	borrarMensajes(idQueue);

	while(key == RUN){
		sleep(3);
		allReady = memoria[pos].allReady;

		showBegin(debug);
		if(allReady == partiesInvolved){
			key = STOP;
			memoria[pos].start = 1;
			showStrLog("PANEL ",debug);
			showStrIntLog("LISTA CONEXION CON ANIMALES ",allReady,debug);
		}
		else{
			showStrLog("PANEL ESPERANDO CONEXION CON ANIMALES",debug);
			showStrIntLog("ANIMALES LISTOS ",allReady,debug);
			showStrIntLog("ANIMALES FALTANTES ",partiesInvolved-allReady,debug);
		}
		showEnd(debug);
	}

	key = RUN;

	while(key == RUN){

		recibirMensaje(idQueue,MSG_PANEL,&msg);
		idAnimal = msg.intSender-MSG_ANIMAL;
		logicSender = msg.intSender;
		idOutput = logicSender;

		showBegin(debug);
		showStrLog("PANEL PROCESANDO INFO",debug);
		showStrIntLog("ID REMINENTE ",logicSender,debug);
		showStrIntLog("ID ANIMAL ",idAnimal,debug);
		

		switch(msg.intEvent){
			case EVT_CORRO:
				showStrStrLog("MENSAJE ",msg.charMensaje,debug);
				cont = atoi(msg.charMensaje);

				animal[idAnimal].id = idAnimal;
				animal[idAnimal].tries ++;
				animal[idAnimal].position +=cont;

				showStrIntLog("VUELTA ",animal[idAnimal].tries,debug);
				showStrIntLog("RECORRIDO ",animal[idAnimal].position,debug);

				max = animal[0].position;

				for(i = 0; i < 3; i++){
					showStrLog("CHEQUEANDO POSICIONES",debug);
					if(animal[i].position >= max){
						showStrIntLog("ID ACTUAL ",animal[i].id,debug);
						showStrIntLog("RECORRIDO ",animal[i].position,debug);	
						idWinning = animal[i].id;
						max = animal[i].position;
					}	
				}

				if(idWinning == 0) showStrIntLog("CONEJO EN 1 CON TOTAL ",max,debug);
				if(idWinning == 1) showStrIntLog("GATO EN 1 CON TOTAL ",max,debug);
				if(idWinning == 2) showStrIntLog("PERRO EN 1 CON TOTAL ",max,debug);


				if(max >= limit){
					key= STOP;
					memset(mensaje,0x00,sizeof(mensaje));
					sprintf(mensaje,"%d",idWinning);
					for( i = 0; i<3; i++){
						
						idReceiver = MSG_ANIMAL + i;
						showStrIntLog("ENVIE MENSAJE A ",idReceiver,debug);
						enviarMensaje(idQueue,idReceiver,MSG_PANEL,EVT_END,mensaje);
					}
					showStrIntLog("GANO LA CARRERA EL ANIMAL ",idWinning,debug);
				}
				else
					enviarMensaje(idQueue,logicSender,MSG_PANEL,EVT_INFO,"RECIBIDO");
				showEnd(debug);
			break;

			default:
				showStrLog("EVENTO SIN DEFINIR",debug);
				showStrIntLog("LOGIC SENDER",logicSender,debug);
				showStrIntLog("ID ANIMAL",idAnimal,debug);
				showEnd(debug);
			break;
		}
		cont = 0;
	}
	shmdt((char *)memoria);
	shmctl(idMemoria,IPC_RMID,(struct shmid_ds *)NULL);
	return 0;
}
