#include "main.h"

/**
 * print_char - print a single character
 * @ap: va_list holding an int (promoted char)
 *
 * Return: number of bytes printed, or -1 on error
 */
int print_char(va_list ap)
{
    int c;

    c = va_arg(ap, int);
    if (_putchar((char)c) < 0)
        return (-1);
    return (1);
}
