#include "main.h"

/**
 * specifiers_handler - handles a single format specifier
 * @specifier: format specifier character
 * @args: variadic arguments list
 * Return: number of characters printed
 */
int specifiers_handler(char specifier, va_list args)
{
	int count = 0;
	char *s;

	if (specifier == 'c')
	{
		count += _putchar((char)va_arg(args, int));
	}
	else if (specifier == 's')
	{
		s = va_arg(args, char *);
		if (s == NULL)
			s = "(null)";
		while (*s)
		{
			_putchar(*s);
			s++;
			count++;
		}
	}
	else
	{
		_putchar('%');
		_putchar(specifier);
		count += 2;
	}
	return (count);
}
