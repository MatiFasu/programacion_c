#include "clave.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "def.h"
#include "stdlib.h"
#include "stdio.h"

void* creoMemoria(int size, int* rIdMemoria){
	void* ptrMemoria;
	int idMemoria = 0;
	idMemoria = shmget(creoClave(),size,0777 | IPC_CREAT);

	if(idMemoria == -1){
		printf("NO SE CONSIGUIO ID PARA MEMORIA COMPARTIDA\n\n");
		exit(0);
	}
	ptrMemoria = (void *)shmat(idMemoria,(char *)0,0);
	*rIdMemoria = idMemoria;
	return ptrMemoria;
}
