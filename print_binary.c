#include "main.h"

/**
 * print_binary - Print an unsigned int in binary
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
	unsigned int mask = 1U << 31;
	int total = 0, started = 0;

	while (mask > 0)
	{
		if (n & mask)
		{
			total += _putchar('1');
			started = 1;
		}
		else if (started)
		{
			total += _putchar('0');
		}
		mask >>= 1;
	}

	if (!started)
		total += _putchar('0');

	return (total);
}
