#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <stdio.h>
#include "funcs.h"

/* Read a single two byte integer from the index file */
#define rdint(indxfile) \
    (ch = getc(indxfile), \
     ((ch > 127) ? (ch - 256) : (ch)) * 256 + getc(indxfile))

void rdints(int c, int * pi, FILE * indxfile);
void rdpartialints(int c, int * pi, FILE * indxfile);    
void rdflags(int c, logical * pf, FILE * indxfile);

#endif