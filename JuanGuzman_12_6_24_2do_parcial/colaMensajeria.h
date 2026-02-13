#ifndef _COLAMENSAJERIA
#define _COLAMENSAJERIA

int creoColaMensajes();
int enviarMensaje(int idQueue,long rLongDest, int rIntRte, int rIntEvent,char* rpCharMsg);
int recibirMensaje(int idQueue,long rLongDest,Mensaje* rMsg);
int borrarMensajes(int idQueue);

#endif
