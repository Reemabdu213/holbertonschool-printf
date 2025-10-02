#include "main.h"

/**
 * _putchar - Write one character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_text - Print a string
 * @s: pointer to string
 *
 * Return: number of characters printed
 */
static int print_text(char *s)
{
	int total = 0;

	if (s == (char *)0)
		s = "(null)";

	while (*s)
	{
		total += _putchar(*s);
		s++;
	}
	return (total);
}

/**
 * print_int - Print integer
 * @n: number to print
 *
 * Return: number of characters printed
 */
static int print_int(int n)
{
	unsigned int val;
	int total = 0;

	if (n < 0)
	{
		total += _putchar('-');
		val = (unsigned int)(-n);
	}
	else
		val = (unsigned int)n;

	if (val / 10)
		total += print_int((int)(val / 10));

	total += _putchar((val % 10) + '0');
	return (total);
}

/**
 * handle_format - Manage one format specifier
 * @c: the format character
 * @ap: list of arguments
 *
 * Return: number of characters printed
 */
static int handle_format(char c, va_list ap)
{
if (c == 'c')
return (_putchar((char)va_arg(ap, int)));
if (c == 's')
return (print_text(va_arg(ap, char *)));
if (c == '%')
return (_putchar('%'));
if (c == 'd' || c == 'i')
return (print_int(va_arg(ap, int)));
if (c == 'b')
return (print_binary(va_arg(ap, unsigned int)));
if (c == 'u')
return (print_uint(va_arg(ap, unsigned int)));
if (c == 'o')
return (print_octal(va_arg(ap, unsigned int)));
if (c == 'x')
return (print_hex_low(va_arg(ap, unsigned int)));
if (c == 'X')
return (print_hex_up(va_arg(ap, unsigned int)));

	/* Unknown specifier: print it raw */
	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * _printf - Produce output like printf
 * @format: format string
 *
 * Return: number of characters printed, -1 if error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;

	if (format == (const char *)0)
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				va_end(ap);
				return (-1);
			}
			count += handle_format(*format, ap);
		}
		format++;
	}
	va_end(ap);

	return (count);
}
