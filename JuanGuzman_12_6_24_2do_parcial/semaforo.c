#include "stdio.h"
#include "sys/ipc.h"
#include "sys/sem.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#include "semaforo.h"
#include "clave.h"
#include "def.h"

int creoSemaforo(){
	key_t clave = creoClave(CLAVE_BASE);
	int idSemaforo = semget(clave,1,0600|IPC_CREAT);

	if(idSemaforo == -1){
		printf("Error: no puedo crear semaforo\n");
		exit(0);
	}
	return idSemaforo;	
}

void iniciaSemaforo(int idSemaforo, int valor){
	semctl(idSemaforo,0,SETVAL,valor);
}

void levantaSemaforo(int idSemaforo, int debug){
	struct sembuf operacion;
	if(debug == DEBUG_ON)printf("LEVANTA SEMAFORO\n\n");
	operacion.sem_num = 0;
	operacion.sem_op = 1;
	operacion.sem_flg = 0;
	semop(idSemaforo,&operacion,1);
}

void esperaSemaforo(int idSemaforo, int debug){
	struct sembuf operacion;
	if(debug == DEBUG_ON)printf("ESPERA SEMAFORO\n\n");
	operacion.sem_num = 0;
	operacion.sem_op = -1;
	operacion.sem_flg = 0;
	semop(idSemaforo,&operacion,1);
}

