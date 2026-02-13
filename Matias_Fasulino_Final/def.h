#ifndef _DEF
#define _DEF

#define DESDE 10
#define HASTA 20

#define CANT_ARR 10

#define CANTIDAD 10

#define LARGO 100

#define CANTIDAD_PARTIDA 10

#define INTERVALO_PARTIDA 5000

#define INTERVALO_PRODUCTO 100

#define TRUE 1
#define FALSE 0

#define VERDE 1
#define ROJO 0

#define CLAVE_BASE 39

#define CANT 10

#define CANT_TOTAL 10

#define LARGO_TMENSAJE 1024

/* --- EXAMEN FINAL --- */

/* --- PAISES --- */

#define CANTIDAD_BARCOS 1
#define CANTIDAD_PAISES 3

typedef enum
{
	MSG_NADIE,
	MSG_TABLERO,
	MSG_PAIS
}Destinos;

typedef enum
{
	EVT_NINGUNO,
	EVT_DISPARAR,
	EVT_HUNDIDO,
	EVT_FIN
}Eventos;

#endif
