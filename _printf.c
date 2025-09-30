#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

static int put_char(char c)
{
    return (write(1, &c, 1));
}

static int put_str(char *s)
{
    int cnt = 0;

    if (s == NULL)
        s = "(null)";

    while (*s)
    {
        write(1, s, 1);
        s++;
        cnt++;
    }
    return (cnt);
}

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] != '%')
        {
            count += put_char(format[i]);
            i++;
            continue;
        }
        i++;
        if (format[i] == '\0')
        {
            va_end(args);
            return (-1);
        }

        if (format[i] == 'c')
            count += put_char((char)va_arg(args, int));
        else if (format[i] == 's')
            count += put_str(va_arg(args, char *));
        else if (format[i] == '%')
            count += put_char('%');
        else if (format[i] == 'd' || format[i] == 'i')
            count += print_int(va_arg(args, int));
        else
        {
            count += put_char('%');
            count += put_char(format[i]);
        }
        i++;
    }

    va_end(args);
    return (count);
}				
