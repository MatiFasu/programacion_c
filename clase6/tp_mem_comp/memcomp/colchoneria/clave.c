#include "stdio.h"
#include "stdlib.h"
#include "sys/ipc.h"
#include "clave.h"
#include "global.h"

key_t creo_clave()
{
	key_t clave;
	clave = ftok ("/bin/ls", CLAVE_GLOBAL);
	if (clave == (key_t)-1)
	{
		printf("No puedo conseguir clave del semaforo \n");
		exit(0);
	}
	return clave;
}

