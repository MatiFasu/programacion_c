#ifndef _GLOBAL
#define _GLOBAL

typedef struct mistruct 
{
	int inEntero;
}MISTRUCT;

typedef struct tipo_dato dato;

struct tipo_dato
{
	int cajero;
	int importe;
	int cheque;
	int listo;
};

struct Tesorero
{
	int total_cant_dep;
	int total_cant_efec;
	int total_cant_cheq;

	int total_pesos_dep;
	int total_pesos_efec;
	int total_pesos_cheq;

	int vtotal_cant_dep[3];
	int vtotal_cant_efec[3];
	int vtotal_cant_cheq[3];

	int vtotal_pesos_dep[3];
	int vtotal_pesos_efec[3];
	int vtotal_pesos_cheq[3];
};



extern int ginEnteroP;

#endif
