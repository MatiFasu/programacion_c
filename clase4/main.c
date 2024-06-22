#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <def.h>
#include <archivos.h>
#include <global.h>
#include <clave.h>



int main(int argc, char* argv[]) {

	key_t clave = creo_clave();

	printf("Claseee 4\n");

	printf("Clave: ", clave);
	

	printf("\n");
	return 0;
}
