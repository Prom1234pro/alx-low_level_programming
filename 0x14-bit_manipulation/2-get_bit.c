#include <stdio.h>
#include "main.h"

/**
 * get_bit - converts a number to binary
 * @n: number to convert
 * @index: number to convert
 *
 * Return:int
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	return ((n >> index) & 1);
}
