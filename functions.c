#include "main.h"

/**
 * _putchar - Prints a character to stdout.
 * @c: The character to print.
 *
 * Return: 1 on success.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string to stdout.
 * @str: The string to print.
 *
 * Return: Number of characters printed.
 */
int print_string(char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";

	while (*str)
		i += _putchar(*str++);

	return (i);
}

/**
 * print_unsigned - Prints an unsigned integer in base 10.
 * @n: The number to print.
 *
 * Return: Number of characters printed.
 */
int print_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10);

	count += _putchar((n % 10) + '0');

	return (count);
}

/**
 * print_number - Prints a signed integer in base 10.
 * @n: The number to print (can be negative).
 *
 * Description: Handles INT_MIN safely by promoting to long before
 * converting to unsigned.
 *
 * Return: Number of characters printed.
 */
int print_number(int n)
{
	int count = 0;
	unsigned int u;

	if (n < 0)
	{
		count += _putchar('-');
		u = (unsigned int)(-(long)n);
	}
	else
	{
		u = (unsigned int)n;
	}

	count += print_unsigned(u);

	return (count);
}
