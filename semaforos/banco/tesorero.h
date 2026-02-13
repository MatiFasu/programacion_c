#ifndef _tesorero
#define _tesorero


typedef struct totalcajero{
	int tefectivo;
	int cantefectivo;
	int tcheque;
	int cantcheque;
}totalcajero;

void generatesorero();
struct totalcajero gettotal(int nrocajero);
struct totalcajero sumacajeros(struct totalcajero cajero1,struct totalcajero cajero2,struct totalcajero cajero3);

#endif
