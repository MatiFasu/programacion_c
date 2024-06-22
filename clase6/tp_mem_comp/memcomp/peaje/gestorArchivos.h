#ifndef _gestorArchivos
#define _gestorArchivos
FILE *archivo;
int openfile(char filename[]);
int openfileread(char filename[]);
int openfileoverwrite(char filename[]);
int openfileclean(char filename[]);
#endif
