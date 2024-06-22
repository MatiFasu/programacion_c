CC=gcc-4.1

CFLAGS = -Wall -O4 -std=gnu89 -pedantic-errors 
HEADERS = -I./
all: colchoneria vendedor

colchoneria: colchoneria.c colchoneria.h memcomp.c funciones.c semaforo.c clave.c

	$(CC) -o colchoneria colchoneria.c memcomp.c funciones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)

vendedor: vendedor.c vendedor.h memcomp.c funciones.c semaforo.c clave.c

	$(CC) -o vendedor vendedor.c memcomp.c funciones.c semaforo.c clave.c $(CFLAGS) $(HEADERS)


clean:
	rm -rf *o colchoneria vendedor
	
	
	
