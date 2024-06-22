CC = gcc-4.1

CFLAGS = -Wall -std=gnu89 -pedantic-errors -O3

HEADERS = -I./

all: prog

prog:
	$(CC) -o miprog main.c funciones.c $(CFLAGS) $(HEADERS)

clean: rm -rf *o miprog

