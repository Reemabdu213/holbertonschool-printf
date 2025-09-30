#include "main.h"

/**
 * print_normal_char - Prints a normal character (not a specifier)
 * @c: Character to print
 *
 * Return: Number of characters printed (1)
 */
int print_normal_char(char c)
{
	_putchar(c);
	return (1);
}

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
				return (-1); /* Case: % at end */
			}

			result = handle_specifier(format[i], args);
			if (result == -1)
			{
				count += print_normal_char('%');
				count += print_normal_char(format[i]);
			}
			else
			{
				count += result;
			}
		}
		else
		{
			count += print_normal_char(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}
