#include "main.h"

/**
 * set_bit - converts a number to binary
 * @n: number to convert
 * @index: number to convert
 *
 * Return:int
 */


int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	unsigned long int mask = 1UL << index;
	*n |= mask;

	return (1);
}
