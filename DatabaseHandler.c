#include "DatabaseHandler.h"

int ReadInteger(FILE * file){
	int temp = getc(file);
	return ((temp > 127) ? (temp - 256) : (temp)) * 256 + getc(file);
}

/* Read a number of two byte ints from the index file */

void ReadIntegerArray(int arraySize, int * arrayInt, FILE * file)
{
    int ch;	/* Local variable for rdint */

    while (arraySize-- != 0)
	*arrayInt++ = ReadInteger(file);
}

/* Read a partial array of ints.  These are stored as index,value
 * pairs.
 */

void ReadKeyValueArray(int typeOfNumber, int * array, FILE * file)
{
    int ch;	/* Local variable for rdint */

    while (1) {
		int i;

		if (IsByte(typeOfNumber)) {
		    i = getc(file);
		    if (i == 255)
			return;
		} else {
		    i = ReadInteger(file);
		    if (i == -1)
			return;
		}

		array[i] = ReadInteger(file);
    }
}

logical IsByte(int typeOfNumner) {
	return typeOfNumner < 255;
}

/* Read a number of one byte flags from the index file */

void ReadFlagArray(int numFlags, logical * flags, FILE * file)
{
    while (numFlags-- != 0)
	*flags++ = getc(file);
}