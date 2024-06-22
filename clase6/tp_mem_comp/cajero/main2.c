#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "time.h"
#include "unistd.h"

#include <funciones.h>
#include <def.h>
#include <archivos.h>
#include <global.h>
#include <clave.h>
#include <semaforo.h>
#include <memoria.h>



int main(int argc, char* argv[]) {

	dato *memoria = NULL;
	int id_memoria;
	int i, j;
	int id_semaforo;

	struct Tesorero t = subirTesorero();

	id_semaforo = creo_semaforo();

	inicia_semaforo(id_semaforo, VERDE);

	memoria = (dato*)creo_memoria(sizeof(dato)*CANTIDAD, &id_memoria);
	
	for(i=0; i<100; i++) {
		memoria[i].listo = 0;
	}

	while(1)
	{		
		
		printf("TESORERO\n");

		espera_semaforo(id_semaforo);	

			i=0;
			while( i < 100) 
			{
				if(memoria[i].listo == 1) {

					if(memoria[i].cajero < 3) {
						
						memoria[i].listo = 0;
							
						t.total_cant_dep++;
						t.total_pesos_dep += memoria[i].importe;
						
						t.vtotal_cant_dep[memoria[i].cajero - 1]++;
						t.vtotal_pesos_dep[memoria[i].cajero - 1] += memoria[i].importe;

						if(memoria[i].cheque == 0) {
							t.total_cant_efec++;
							t.total_pesos_efec += memoria[i].importe;
							t.vtotal_cant_efec[memoria[i].cajero - 1]++;
							t.vtotal_pesos_efec[memoria[i].cajero - 1] += memoria[i].importe;
						} else {
							t.total_cant_cheq++;
							t.total_pesos_cheq += memoria[i].importe;
							t.vtotal_cant_cheq[memoria[i].cajero - 1]++;
							t.vtotal_pesos_cheq[memoria[i].cajero - 1] += memoria[i].importe;
						}


						printf("\n\nTOTAL \n TC-EFEC - T$-EFEC - TC-CHEQ - T$-CHEQ\n");
						printf("  %d - %d - %d - %d", t.total_cant_efec, t.total_pesos_efec, t.total_cant_cheq, 							t.total_pesos_cheq);

						for(j=0; j < 3; j++) {
							printf("\nCAJERO %d\n", j+1);
							printf("  %d - %d - %d - %d \n", t.vtotal_cant_efec[j], t.vtotal_pesos_efec[j], 								t.vtotal_cant_cheq[j], t.vtotal_pesos_cheq[j]);
						}
					}
				}	
			
				i++;
			}

		levanta_semaforo(id_semaforo);
		sleep(12);
	}


	shmdt ((char *)memoria);
	shmctl (id_memoria, IPC_RMID, (struct shmid_ds *)NULL);

	printf("\n");
	return 0;
}
