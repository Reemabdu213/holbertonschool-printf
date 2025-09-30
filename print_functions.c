#include "main.h"

/**
 * print_char - Prints a character
 * @args: argument list containing the character
 *
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @args: argument list containing the string
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int i = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - Prints a percent sign
 * @args: argument list (unused)
 *
 * Return: Number of characters printed (1)
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}
