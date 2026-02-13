#ifndef _SEMAFORO
#define _SEMAFORO

int creoSemaforo();
void iniciaSemaforo(int idSemaforo, int valor);
void levantaSemaforo(int idSemaforo, int debug);
void esperaSemaforo(int idSemaforo, int debug);

#endif
