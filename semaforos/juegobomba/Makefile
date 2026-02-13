CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors
HEADERS = -I./
#all: cajero tesorero

bomba: bomba.c gestorArchivos.c funciones.c semaforo.c clave.c

	$(CC) -o bomba bomba.c gestorArchivos.c funciones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)

tesorero: tesorero.c tesorero.h gestorArchivos.c funciones.c semaforo.c clave.c

	$(CC) -o tesorero tesorero.c gestorArchivos.c funciones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)


clean:
	rm -rf *o bomba
	
	
	
