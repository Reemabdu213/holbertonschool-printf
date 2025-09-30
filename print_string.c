#include "main.h"
#include <stddef.h>

/**
 * print_cstring - print a C string safely
 * @s: pointer to string (may be NULL)
 *
 * Return: number of bytes printed, or -1 on error
 */
int print_cstring(const char *s)
{
    int count;
    const char *nulls;

    count = 0;
    nulls = "(null)";
    if (s == NULL)
    {
        while (*nulls)
        {
            if (_putchar(*nulls) < 0)
                return (-1);
            nulls++;
            count++;
        }
        return (count);
    }
    while (*s)
    {
        if (_putchar(*s) < 0)
            return (-1);
        s++;
        count++;
    }
    return (count);
}

/**
 * print_string - print a string from va_list
 * @ap: va_list holding the string
 *
 * Return: number of bytes printed, or -1 on error
 */
int print_string(va_list ap)
{
    const char *s;

    s = va_arg(ap, const char *);
    return (print_cstring(s));
}
