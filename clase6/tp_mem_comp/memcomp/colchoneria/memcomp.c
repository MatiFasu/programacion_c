#include "stdio.h"
#include "sys/shm.h"
#include "memcomp.h"
#include "clave.h"
#include "sys/ipc.h"
#include "stdlib.h"
#include "global.h"

void* creo_memoria(int size,int *r_id_memoria){
	void *ptr_memoria;
	int id_memoria;
	id_memoria = shmget(creo_clave(CLAVE_GLOBAL), size, 0777 | IPC_CREAT);
	if(id_memoria == -1)
	{
		printf("No consigo id para memoria comparida \n");
		return 0;
	}
	ptr_memoria = (void *)shmat(id_memoria,(char *)0,0);
	if(ptr_memoria == NULL)
	{
		printf("No consigo memoria compartida\n");
		return 0;
	}
	*r_id_memoria = id_memoria;
	return ptr_memoria;
}
