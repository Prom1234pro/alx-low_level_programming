#include "main.h"

/**
 * clear_bit - converts a number to binary
 * @n: number to convert
 * @index: number to convert
 *
 * Return:int
 */


int clear_bit(unsigned long int *n, unsigned int index)
{
	/* Check if index is valid */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Clear the bit at index by shifting 1 to the left and negating */
	*n &= ~(1ul << index);

	return (1);
}
