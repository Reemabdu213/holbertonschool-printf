#include "main.h"

/**
 * print_text - Print a NUL-terminated string.
 * @s: Pointer to string (may be NULL).
 *
 * Return: Number of characters printed.
 */
static int print_text(char *s)
{
	int total = 0;

	if (s == (char *)0)
		s = "(null)";

	while (*s)
		total += _putchar(*s++);

	return (total);
}

/**
 * print_int - Print a signed decimal integer.
 * @n: Integer value.
 *
 * Return: Number of characters printed.
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
 * handle_format - Handle a single conversion specifier.
 * @c: Format character.
 * @ap: Variadic argument list.
 *
 * Return: Number of characters printed for this specifier.
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

	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * _printf - Produce output according to a format string.
 * @format: Format string (must not be NULL).
 *
 * Return: Count of printed characters, or -1 on error.
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
				flush_buffer();
				return (-1);
			}
			count += handle_format(*format, ap);
		}
		format++;
	}
	va_end(ap);

	flush_buffer();
	return (count);
}
