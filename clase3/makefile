CC=gcc-4.1

CFLAGS= -Wall -pedantic-errors -O3 -std=gnu89

HEADERS= -I./

all= clean miprog

miprog: main.c
	$(CC) -o prog main.c funciones.c archivos.c $(CFLAGS) $(HEADERS)

clean: rm -rf *o miprog
