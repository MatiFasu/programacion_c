CC=gcc-4.1 -pthread

CFLAGS= -Wall -pedantic-errors -O3 -std=gnu89

HEADERS= -I./

all: clean main main2

main:
	$(CC) -o main main.c funciones.c archivos.c global.c clave.c semaforo.c memoria.c cola.c $(CFLAGS) $(HEADERS)

main2:
	$(CC) -o main2 main2.c funciones.c archivos.c global.c clave.c semaforo.c memoria.c cola.c jugadorThread.c $(CFLAGS) $(HEADERS)

clean:
	rm -rf *o main main2
