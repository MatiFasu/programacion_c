CC=gcc-4.1

CFLAGS= -Wall -pedantic-errors -O3 -std=gnu89

HEADERS= -I./

all: clean main main2

main:
	$(CC) -o repositor repositor.c funciones.c archivos.c global.c clave.c semaforo.c memoria.c cola.c $(CFLAGS) $(HEADERS)

main2:
	$(CC) -o supermercado supermercado.c funciones.c archivos.c global.c clave.c semaforo.c memoria.c cola.c $(CFLAGS) $(HEADERS)

clean:
	rm -rf *o main main2
