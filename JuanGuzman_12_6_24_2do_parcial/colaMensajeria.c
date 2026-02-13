/*una cola se mensaje nada mas se usara*/
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "sys/ipc.h"
#include "sys/msg.h"
#include "clave.h"

#include "def.h"
#include "global.h"

/*EVENTO FIN CUANDO SE ENVIE EL ULTIMO MENSAJE PARA ELIMINAR QUEUE?*/


int creoColaMensajes(){
	int id = msgget(creoClave(),0600 | IPC_CREAT);
	if(id == -1){
		printf("ERROR AL OBTENER MSG QUEUE ID\n\n");
		exit(-1);
	}
	return id;
}

int enviarMensaje(int idQueue,long rLongDest, int rIntRte, int rIntEvent,char* rpCharMsg){
	Mensaje msg;
	msg.longDest = rLongDest;
	msg.intSender = rIntRte;
	msg.intEvent = rIntEvent;
	strcpy(msg.charMensaje,rpCharMsg);
	return msgsnd(idQueue,(struct msgbuf *)&msg,sizeof(msg.intSender)+sizeof(msg.intEvent)+sizeof(msg.charMensaje),IPC_NOWAIT);
}

int recibirMensaje(int idQueue,long rLongDest,Mensaje* rMsg){
	Mensaje msg;
	int result;
	result = msgrcv(idQueue,(struct msgbuf *)&msg,sizeof(msg.intSender)+sizeof(msg.intEvent)+sizeof(msg.charMensaje),rLongDest,0);
	rMsg->longDest = msg.longDest;
	rMsg->intSender = msg.intSender;
	rMsg->intEvent = msg.intEvent;
	strcpy(rMsg->charMensaje,msg.charMensaje);
	return result;
}

int borrarMensajes(int idQueue){
	Mensaje msg;
	int result;
	do{
		result = msgrcv(idQueue,(struct msgbuf *)&msg,sizeof(msg.intSender)+sizeof(msg.intEvent)+sizeof(msg.charMensaje),0,IPC_NOWAIT);
	}while(result>0);
	return result;
}
