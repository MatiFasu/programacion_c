#include <stdio.h>
#include <stdlib.h>
#include "clave.h"
#include <sys/ipc.h>

key_t creo_clave()
{
	key_t clave;

	clave = ftok("/bin/ls", 33);

	if(clave == (key_t)-1) {
		printf("No puedo conseguir clave de producto");
		exit(0);
	}
	
	return clave;
}



