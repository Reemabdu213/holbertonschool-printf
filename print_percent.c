#include "main.h"

/**
 * print_percent - print a literal '%'
 * @ap: unused
 *
 * Return: 1 on success, -1 on error
 */
int print_percent(va_list ap)
{
    (void)ap;
    if (_putchar('%') < 0)
        return (-1);
    return (1);
}
