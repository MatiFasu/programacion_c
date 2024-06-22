CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors 
HEADERS = -I./
all: peaje auto

peaje: peaje.c peaje.h memcomp.c gestorArchivos.c funciones.c semaforo.c clave.c

	$(CC) -o peaje peaje.c memcomp.c funciones.c gestorArchivos.c semaforo.c clave.c $(CFLAGS) $(HEADERS)

auto: auto.c auto.h memcomp.c funciones.c semaforo.c clave.c

	$(CC) -o auto auto.c memcomp.c funciones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)


clean:
	rm -rf *o peaje auto
	
	
	
