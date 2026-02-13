#ifndef _LOGGER
#define _LOGGER

void showStrLog(char *text, int debug);
void showStrStrLog(char *text, char *value, int debug);
void showStrIntLog(char *text, int value, int debug);
void showBegin(int debug);
void showEnd(int debug);
void showSpacer(int debug);
void showStrLongLog(char *text, long value, int debug);

#endif
