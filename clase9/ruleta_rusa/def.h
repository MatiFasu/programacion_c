#ifndef _DEF
#define _DEF

#define DESDE 10
#define HASTA 20

#define CANT_ARR 10

#define CANTIDAD 10

#define LARGO 100

#define TRUE 1
#define FALSE 0

#define VERDE 1
#define ROJO 0

#define CLAVE_BASE 33

#define LARGO_TMENSAJE 1024

typedef enum
{
	MSG_NADIE,
	MSG_REVOLVER,
	MSG_JUGADOR
}Destinos;

typedef enum
{
	EVT_NINGUNO,
	EVT_INICIO,
	EVT_DISPARO,
	EVT_SALVADO,
	EVT_FIN
}Eventos;

#endif
