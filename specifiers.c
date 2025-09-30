#include "main.h"

/**
 * specifiers_handler - handles format specifiers
 * @specifier: format specifier
 * @args: arguments list
 * Return: number of characters printed
 */
int specifiers_handler(char specifier, va_list args)
{
	int count = 0;
	char *str;

	if (specifier == 'c')
	{
		count += _putchar(va_arg(args, int));
	}
	else if (specifier == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		while (*str)
		{
			_putchar(*str);
			str++;
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
