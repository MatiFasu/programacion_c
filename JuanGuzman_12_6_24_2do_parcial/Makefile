CC=gcc-4.1

CFLAGS = -Wall -O3 -std=gnu89 -pedantic-errors -pthread
HEADERS = -I./

CARRERA = carrera.c
PANEL = panel.c

FUNCIONES = clave.c funciones.c memoria.c archivo.c colaMensajeria.c logger.c
LIBRERIAS = def.h global.h clave.h funciones.h memoria.h archivo.h colaMensajeria.h logger.h

F_ANIMAL = threadAnimal.c 
L_ANIMAL = threadAnimal.h

all: cleanPrograms panel carrera

carrera: $(CARRERA) $(FUNCIONES) $(LIBRERIAS) $(F_ANIMAL) $(L_ANIMAL)
	$(CC) -o carrera $(CARRERA) $(FUNCIONES) $(F_ANIMAL) $(CFLAGS) $(HEADERS)

panel: $(PANEL) $(FUNCIONES) $(LIBRERIAS)
	$(CC) -o panel $(PANEL) $(FUNCIONES) $(CFLAGS) $(HEADERS)

cleanPrograms:
	rm -rf *o panel animal


