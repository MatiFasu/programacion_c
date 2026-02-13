#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#include "unistd.h"
#include "def.h"
#include "logger.h"

void showStrLog(char *text,int debug){
	if(debug == DEBUG_ON)
		printf("     %s\n",text);
}

void showStrStrLog(char *text, char *value, int debug){
	if(debug == DEBUG_ON)
		printf("     %s[%s]\n",text,value);
}

void showStrIntLog(char *text, int value, int debug){
	if(debug == DEBUG_ON)
		printf("     %s[%d]\n",text,value);
}

void showStrLongLog(char *text, long value, int debug){
	if(debug == DEBUG_ON)
		printf("     %s[%ld]\n",text,value);
}

void showBegin(int debug){
	if(debug == DEBUG_ON)
		printf("-----------------------------\n");
}

void showEnd(int debug){
	if(debug == DEBUG_ON)
		printf("-----------------------------\n\n");
}

void showSpacer(int debug){
	if(debug == DEBUG_ON)
		printf("\n");
}
