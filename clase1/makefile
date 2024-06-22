CC = gcc-4.1

CFLAGS = -Wall -pedantic-errors -O3 -std=gnu89

HEADERS = -I./

all = clean miprog

prog:
	$(CC) -o miprog main.c funciones.c $(CFLAGS) $(HEADERS)

clean: rm -rf *o miprog
