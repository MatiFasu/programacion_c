#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <clave.h>
#include <def.h>

key_t creo_clave()
{
	key_t clave;

	clave = ftok("/bin/ls", 55);

	if(clave == (key_t)-1) {
		printf("No puedo conseguir clave de producto");
		exit(0);
	}
	
	return clave;
}



