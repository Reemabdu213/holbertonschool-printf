#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, total_length = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			if (format[i] == '%')
			{
				_putchar('%');
				total_length++;
			}
			else
			{
				total_length += specifiers_handler(format[i], args);
			}
		}
		else
		{
			_putchar(format[i]);
			total_length++;
		}
		i++;
	}
	va_end(args);
	return (total_length);
}
