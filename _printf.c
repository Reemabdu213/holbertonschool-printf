#include "main.h"

/**
 * handle_specifier - Handles format specifiers
 * @specifier: The format specifier character
 * @args: Argument list containing the values
 *
 * Return: Number of characters printed
 */
int handle_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(args));
	else if (specifier == 's')
		return (print_string(args));
	else if (specifier == '%')
		return (print_percent(args));

	return (-1);
}

/**
 * _printf - Produces output according to a format
 * @format: Character string composed of zero or more directives
 *
 * Return: Number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, result;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1); /* Error: % at end of string */
			}

			result = handle_specifier(format[i], args);
			if (result == -1)
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
			else
			{
				count += result;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
