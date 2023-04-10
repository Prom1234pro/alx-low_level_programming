#include <stdio.h>
#include "main.h"
/**
 * print_binary - converts a number to binary
 * @n: number to convert
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);
	putchar((n & 1) ? '1' : '0');
}
