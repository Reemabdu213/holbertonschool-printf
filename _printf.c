#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	int i = 0, total = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			total++;
			i++;
			continue;
		}

		i++; /* skip '%' */

		if (format[i] == '\0')
		{
			va_end(args);
			return (-1); /* solitary '%' -> error per checker */
		}

		if (format[i] == '%')
		{
			_putchar('%');
			total++;
		}
		else
		{
			total += specifiers_handler(format[i], args);
		}
		i++;
	}

	va_end(args);
	return (total);
}
