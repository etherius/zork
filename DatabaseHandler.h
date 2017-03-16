#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <stdio.h>
#include "funcs.h"

void ReadIntegerArray(int c, int * pi, FILE * indxfile);
void ReadKeyValueArray(int c, int * pi, FILE * indxfile);    
void ReadFlagArray(int c, logical * pf, FILE * indxfile);
logical IsByte(int typeOfNumner);
int ReadInteger(FILE * file);
#endif