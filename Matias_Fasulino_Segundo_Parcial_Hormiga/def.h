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

#define CLAVE_BASE 33

#define CANT 10

#define CANT_TOTAL 10

#define LARGO_TMENSAJE 1024

/* --- CARRERA HORMIGA --- */

#define META 15
#define CANTIDAD_ANIMALES 3

#define REINA_VEL_MIN 3
#define REINA_VEL_MAX 8

#define ROJA_VEL_MIN 2
#define ROJA_VEL_MAX 7

#define NEGRA_VEL_MIN 1
#define NEGRA_VEL_MAX 9

typedef enum
{
	MSG_NADIE,
	MSG_TABLERO,
	MSG_HORMIGA
}Destinos;

typedef enum
{
	EVT_NINGUNO,
	EVT_CORRO,
	EVT_FIN
}Eventos;

#endif
