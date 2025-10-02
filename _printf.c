#include "main.h"

#define BUF_SIZE 1024

static char buffer[BUF_SIZE];
static int buf_index = 0;

static void flush_buffer(void)
{
	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
		buf_index = 0;
	}
}

int _putchar(char c)
{
	if (buf_index >= BUF_SIZE)
		flush_buffer();

	buffer[buf_index++] = c;
	return (1);
}

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

static int print_unsigned(unsigned int n)
{
	int total = 0;

	if (n / 10)
		total += print_unsigned(n / 10);

	total += _putchar((n % 10) + '0');
	return (total);
}

static int print_octal(unsigned int n)
{
	int total = 0;

	if (n / 8)
		total += print_octal(n / 8);

	total += _putchar((n % 8) + '0');
	return (total);
}

static int print_hex(unsigned int n, int uppercase)
{
	int total = 0;
	char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n / 16)
		total += print_hex(n / 16, uppercase);

	total += _putchar(digits[n % 16]);
	return (total);
}

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
		return (print_unsigned(va_arg(ap, unsigned int)));
	if (c == 'o')
		return (print_octal(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (print_hex(va_arg(ap, unsigned int), 0));
	if (c == 'X')
		return (print_hex(va_arg(ap, unsigned int), 1));

	_putchar('%');
	_putchar(c);
	return (2);
}

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
