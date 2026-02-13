#ifndef _GLOBAL
#define _GLOBAL
#include "def.h"
#include "pthread.h"
FILE *fileHandle;
FILE *fileTemp;

/*VUELOS*/
typedef struct Vuelo{
	int nVuelo;
	char destino[40];
	int pasajeros;
}Vuelo;

/*REPORTE*/
typedef struct Reporte{
	int importeTotalEfec;
	int importeTotalCheq;
	int cantOpUno;
	int cantOpCero;
}Reporte;

/*PANEL*/
typedef struct Panel{
	int id;
	char mensaje[64];
}Panel;

/*PEDIDOS*/
typedef struct Pedido{
	int idPedido;
	int precioParcial;
	int precioTotal;
	int flagPostre;
}Pedido;

/*MEDICAMENTOS*/
typedef struct Medicamento{
	int idPedido;
	int cantidadProducida;
}Medicamento;

/*BANCO*/
typedef struct Dato{
	int idCajero;
	int importe;
	int operacion;	
	int listo;
}Dato;

/*JUEGO ADIVINA NUMERO*/
typedef struct Juego{
	char nombreJugador[LARGO_NOMBRE];
	int numPensado;
	int estadoAcierto;
}Juego;

/*DON PEPITO DON JOSE, MSG QUEUE*/
typedef struct Jugador{
	int acierto;
	int idJugador;
	int numero;
	int intentos;
}Jugador;

/*PIENSA UN NUMERO THREAD*/
typedef struct Jueguito{
	int acierto;
}Jueguito;


typedef struct Player{
	int idJugador;
	int aciertos;
}Player;

/*BINGO THREAD*/

/*PIENSO UN NUMERO MULTI THREAD + MSG QUEUE*/
typedef struct GameSession{
	int done;
	int total;
}GameSession;

/*MULTI THREAD*/
	/*RULETA RUSA*/
typedef struct RuletaPlayer{
	int idPlayer;
	int idQueue;
	int players;
}RuletaPlayer;

	/*BINGO*/
typedef struct Bolillero{
	int idQueue;
	int players;
}Bolillero;

typedef struct Session{
	int idJugador;
	int bolilla;
}Session;

typedef struct BingoSession{
	int allReady;
	int start;
}BingoSession;

typedef struct GamePlayer{
	int idPlayer;
	int idQueue;
	int players;
	int aciertos;
}GamePlayer;

/*GENERIC*/
	/*MENSAJE QUEUE*/
typedef struct Mensaje{
	long longDest;
	int intSender;
	int intEvent;
	char charMensaje[LARGO_MENSAJE];
}Mensaje;

typedef enum{
	MSG_NONE,
	MSG_PANEL,
	MSG_ANIMAL
}Destinations;

typedef enum{
	EVT_NONE,
	EVT_CORRO,
	EVT_INFO,
	EVT_END
}Events;

typedef struct Animal{
	int idQueue;
	int id;
	char nombre[30];
	int tries;
	int position;
	int players;
	int minPasos;
	int maxPasos;
}Animal;


typedef struct CarreraSession{
	int allReady;
	int start;
}CarreraSession;

pthread_mutex_t mutex;

/*EXTERN VAR*/
extern int gInExternF;

#endif


