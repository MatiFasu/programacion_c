#include "stdlib.h"
#include "stdio.h"
#include "gestorArchivos.h"
#include "global.h"
#include "semaforo.h"
#include "time.h"

int main (int argc, char const *argv[]){
	int optmenu= 0, id_semaforo;
	id_semaforo = creo_semaforo();
	inicia_semaforo(id_semaforo,VERDE);
	srand(time(0));
	if (argc > 1)
	{
	espera_semaforo(id_semaforo);
				cargavuelorandom(atoi(argv[1]));
				levanta_semaforo(id_semaforo);
	}
	while (optmenu != -1){
		printf("\n \nIngrese una opcion: \n");
		printf("1 Carga un vuelo\n");
		printf("2 Genera lista reservas\n");
		printf("3 Carga vuelos loop\n");
		printf("-1 Salir \n");
		scanf("%d", &optmenu);

		switch(optmenu)
		{
			case 1:
				espera_semaforo(id_semaforo);
				cargavuelo();
				levanta_semaforo(id_semaforo);
				break;
			case 2:
				espera_semaforo(id_semaforo);
				generareservas();
				levanta_semaforo(id_semaforo);
				break;
			case 3:
				espera_semaforo(id_semaforo);
				cargavuelorandom(10);
				levanta_semaforo(id_semaforo);
								
				break;
			case -1:
				printf("\nBye\n");
				break;
			default:
				printf("%d no es un codigo valido", optmenu);
				break;
		
		}
	}

return 0;
}

