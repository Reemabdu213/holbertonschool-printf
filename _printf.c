#include "main.h"
#include <stddef.h>

/**
 * choose_printer - get function for a specifier
 * @c: specifier character
 *
 * Return: function pointer or NULL if unknown
 */
static int (*choose_printer(char c))(va_list)
{
    int i;
    fmt_t specs[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'\0', NULL}
    };

    for (i = 0; specs[i].sym != '\0'; i++)
    {
        if (specs[i].sym == c)
            return (specs[i].fn);
    }
    return (NULL);
}

/**
 * _printf - simplified printf (%c, %s, %%)
 * @format: format string
 *
 * Return: number of printed bytes, or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list ap;
    int count, r;
    const char *p;
    int (*fn)(va_list);

    if (format == NULL)
        return (-1);

    va_start(ap, format);
    count = 0;
    p = format;

    while (*p)
    {
        if (*p != '%')
        {
            if (_putchar(*p) < 0)
            {
                va_end(ap);
                return (-1);
            }
            count++;
            p++;
            continue;
        }

        p++;
        if (*p == '\0')
        {
            if (_putchar('%') < 0)
            {
                va_end(ap);
                return (-1);
            }
            count++;
            break;
        }

        fn = choose_printer(*p);
        if (fn != NULL)
        {
            r = fn(ap);
            if (r < 0)
            {
                va_end(ap);
                return (-1);
            }
            count += r;
        }
        else
        {
            if (_putchar('%') < 0 || _putchar(*p) < 0)
            {
                va_end(ap);
                return (-1);
            }
            count += 2;
        }
        p++;
    }

    va_end(ap);
    return (count);
}
