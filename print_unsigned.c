#include "main.h"

/**
 * print_unsigned_base - Print an unsigned integer in a given base
 * @n: number to print
 * @base: radix to use (e.g. 8, 10, 16)
 * @uppercase: if non-zero, use 'A'..'F'; otherwise 'a'..'f'
 *
 * Return: number of characters printed
 */
int print_unsigned_base(unsigned int n, unsigned int base, int uppercase)
{
	int total = 0;
	unsigned int digit;

	if (n / base)
		total += print_unsigned_base(n / base, base, uppercase);

	digit = n % base;
	if (digit < 10)
		total += _putchar('0' + digit);
	else
		total += _putchar((uppercase ? 'A' : 'a') + (digit - 10));

	return (total);
}

/**
 * print_uint - Print an unsigned integer in decimal (%u)
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_uint(unsigned int n)
{
	return (print_unsigned_base(n, 10, 0));
}

/**
 * print_octal - Print an unsigned integer in octal (%o)
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_octal(unsigned int n)
{
	return (print_unsigned_base(n, 8, 0));
}

/**
 * print_hex_low - Print an unsigned integer in lowercase hex (%x)
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_hex_low(unsigned int n)
{
	return (print_unsigned_base(n, 16, 0));
}

/**
 * print_hex_up - Print an unsigned integer in uppercase hex (%X)
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_hex_up(unsigned int n)
{
	return (print_unsigned_base(n, 16, 1));
} 
