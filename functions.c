#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a character
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);
	return (_putchar(c));
}

/**
 * print_string - prints a string
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		_putchar(*s++);
		count++;
	}
	return (count);
}
