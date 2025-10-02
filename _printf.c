#include "main.h"
#include <stdarg.h>
#include <unistd.h>

#define BUF_SIZE 1024

/* Buffer for _putchar */
static char buffer[BUF_SIZE];
static int buf_index = 0;

/* Flush buffer to stdout */
static void flush_buffer(void)
{
    if (buf_index > 0)
    {
        write(1, buffer, buf_index);
        buf_index = 0;
    }
}

/* _putchar with buffer support */
int _putchar(char c)
{
    if (buf_index >= BUF_SIZE)
        flush_buffer();

    buffer[buf_index++] = c;
    return 1;
}

/* Print string (for %s) */
static int print_text(char *s)
{
    int total = 0;

    if (!s)
        s = "(null)";

    while (*s)
        total += _putchar(*s++);

    return total;
}

/* Print integer (for %d, %i) */
static int print_int(int n)
{
    unsigned int val;
    int total = 0;

    if (n < 0)
    {
        total += _putchar('-');
        val = -n;
    }
    else
        val = n;

    if (val / 10)
        total += print_int(val / 10);

    total += _putchar((val % 10) + '0');
    return total;
}

/* Advanced: unsigned integer (%u) */
static int print_unsigned(unsigned int n)
{
    int total = 0;

    if (n / 10)
        total += print_unsigned(n / 10);

    total += _putchar((n % 10) + '0');
    return total;
}

/* Advanced: octal (%o) */
static int print_octal(unsigned int n)
{
    int total = 0;

    if (n / 8)
        total += print_octal(n / 8);

    total += _putchar((n % 8) + '0');
    return total;
}

/* Advanced: hexadecimal (%x, %X) */
static int print_hex(unsigned int n, int uppercase)
{
    int total = 0;
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16)
        total += print_hex(n / 16, uppercase);

    total += _putchar(digits[n % 16]);
    return total;
}

/* Advanced: binary (%b) */
static int print_binary(unsigned int n)
{
    unsigned int mask = 1U << 31;
    int total = 0, started = 0;

    while (mask)
    {
        if (n & mask)
        {
            total += _putchar('1');
            started = 1;
        }
        else if (started)
            total += _putchar('0');

        mask >>= 1;
    }

    if (!started)
        total += _putchar('0');

    return total;
}

/* Advanced: special string (%S) */
static int print_special_string(char *s)
{
    int total = 0;
    char *hex_digits = "0123456789ABCDEF";

    if (!s)
        s = "(null)";

    while (*s)
    {
        if ((*s > 0 && *s < 32) || *s >= 127)
        {
            total += _putchar('\\');
            total += _putchar('x');
            total += _putchar(hex_digits[(*s >> 4) & 0xF]);
            total += _putchar(hex_digits[*s & 0xF]);
        }
        else
            total += _putchar(*s);
        s++;
    }

    return total;
}

/* Advanced: pointer (%p) */
static int print_pointer(void *ptr)
{
    unsigned long n = (unsigned long)ptr;
    int total = 0;

    if (!ptr)
        return print_text("(nil)");

    total += _putchar('0');
    total += _putchar('x');

    char buf[16];
    int i = 0;
    char *digits = "0123456789abcdef";

    while (n)
    {
        buf[i++] = digits[n % 16];
        n /= 16;
    }

    while (i--)
        total += _putchar(buf[i]);

    return total;
}

/* Handle a single format specifier */
static int handle_format(char c, va_list ap)
{
    if (c == 'c')
        return _putchar((char)va_arg(ap, int));
    if (c == 's')
        return print_text(va_arg(ap, char *));
    if (c == 'S')
        return print_special_string(va_arg(ap, char *));
    if (c == '%')
        return _putchar('%');
    if (c == 'd' || c == 'i')
        return print_int(va_arg(ap, int));
    if (c == 'b')
        return print_binary(va_arg(ap, unsigned int));
    if (c == 'u')
        return print_unsigned(va_arg(ap, unsigned int));
    if (c == 'o')
        return print_octal(va_arg(ap, unsigned int));
    if (c == 'x')
        return print_hex(va_arg(ap, unsigned int), 0);
    if (c == 'X')
        return print_hex(va_arg(ap, unsigned int), 1);
    if (c == 'p')
        return print_pointer(va_arg(ap, void *));

    /* Unknown specifier: print raw */
    _putchar('%');
    _putchar(c);
    return 2;
}

/* The main _printf function */
int _printf(const char *format, ...)
{
    va_list ap;
    int count = 0;

    if (!format)
        return -1;

    va_start(ap, format);

    while (*format)
    {
        if (*format != '%')
            count += _putchar(*format);
        else
        {
            format++;
            if (!*format)
            {
                va_end(ap);
                flush_buffer();
                return -1;
            }
            count += handle_format(*format, ap);
        }
        format++;
    }

    va_end(ap);
    flush_buffer();
    return count;
}
