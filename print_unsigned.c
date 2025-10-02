#include "main.h"

/**
 * print_unsigned_base - Print unsigned int in any base
 * @n: number (unsigned)
 * @base: radix (8, 10, 16)
 * @uppercase: non-zero -> A..F, zero -> a..f
 *
 * Return: number of characters printed
 */
int print_unsigned_base(unsigned int n, unsigned int base, int uppercase)
{
	int total = 0;
	unsigned int digit;

	if (base < 2)
		return (0);

	if (n / base)
		total += print_unsigned_base(n / base, base, uppercase);

	digit = n % base;
	if (digit < 10)
		total += _putchar('0' + digit);
	else
		total += _putchar((uppercase ? 'A' : 'a') + (digit - 10));

	return (total);
}

int print_uint(unsigned int n)      { return (print_unsigned_base(n, 10, 0)); }
int print_octal(unsigned int n)     { return (print_unsigned_base(n, 8, 0)); }
int print_hex_low(unsigned int n)   { return (print_unsigned_base(n, 16, 0)); }
int print_hex_up(unsigned int n)    { return (print_unsigned_base(n, 16, 1)); }
