#include "main.h"

/**
 * flip_bits - converts a number to binary
 * @n: number to convert
 * @m: number to convert
 *
 * Return:int
 */


unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result)
	{
		if (xor_result & 1)
			count++;
		xor_result >>= 1;
	}

	return (count);
}
