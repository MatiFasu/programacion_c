#ifndef _DEF
#define _DEF

typedef struct tipo_datos datos;
struct tipo_datos
{
	int dato;
};

typedef enum
{
	MSG_NADIE,				
	MSG_SUPERMERCADO,		
	MSG_REPOSITOR,			
	MSG_CLIENTE	
}Destinos;

typedef enum
{
	EVT_NINGUNO,
	EVT_CONSULTA_STOCK,
	EVT_RESPUESTA_STOCK,
	EVT_SUMA_STOCK,
	EVT_RESTA_STOCK
}Eventos;

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

#endif
