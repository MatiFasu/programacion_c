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

/* --- CARRERA ANIMAL --- */

#define META 117
#define CANTIDAD_ANIMALES 3

#define CNJ_VEL_MIN 4
#define CNJ_VEL_MAX 9

#define GATO_VEL_MIN 1
#define GATO_VEL_MAX 10

#define PERRO_VEL_MIN 3
#define PERRO_VEL_MAX 8

typedef enum
{
	MSG_NADIE,
	MSG_TABLERO,
	MSG_ANIMAL
}Destinos;

typedef enum
{
	EVT_NINGUNO,
	EVT_CORRO,
	EVT_FIN
}Eventos;

#endif
