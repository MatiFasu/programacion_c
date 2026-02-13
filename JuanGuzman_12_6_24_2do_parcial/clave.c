#include "clave.h"
#include "sys/ipc.h"
#include "stdlib.h"
#include "stdio.h"

key_t creoClave(){
	key_t key;
	key = ftok("/bin/ls",33);
	if(key == (key_t)-1){
		printf("no pude conseguir clave semaforo, mem compartida, etc\n");
		exit(0);
	}
	return key;
}


