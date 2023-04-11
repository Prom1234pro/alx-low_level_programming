#include "main.h"

/**
 * get_endianness - converts a number to binary
 *
 * Return:int
 */


int get_endianness(void)
{
	union
	{
		unsigned int i;
		char c[4];
	} endian_test = {0x01020304};

	return (endian_test.c[0] == 0x04 ? 1 : 0);
}
