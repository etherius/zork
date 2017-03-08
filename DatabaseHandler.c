#include "DatabaseHandler.h"

/* Read a number of two byte ints from the index file */

void rdints(int c, int * pi, FILE * indxfile)
{
    int ch;	/* Local variable for rdint */

    while (c-- != 0)
	*pi++ = rdint(indxfile);
}

/* Read a partial array of ints.  These are stored as index,value
 * pairs.
 */

void rdpartialints(int c, int * pi, FILE * indxfile)
{
    int ch;	/* Local variable for rdint */

    while (1) {
	int i;

	if (c < 255) {
	    i = getc(indxfile);
	    if (i == 255)
		return;
	}
	else {
	    i = rdint(indxfile);
	    if (i == -1)
		return;
	}

	pi[i] = rdint(indxfile);
    }
}

/* Read a number of one byte flags from the index file */

void rdflags(int c, logical * pf, FILE * indxfile)
{
    while (c-- != 0)
	*pf++ = getc(indxfile);
}