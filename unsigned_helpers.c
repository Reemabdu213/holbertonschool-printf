#include "main.h"

/**
 * print_unsigned - Print unsigned int in decimal
 * @n: number
 * Return: chars printed
 */
int print_unsigned(unsigned int n)
{
    int total = 0;

    if (n / 10)
        total += print_unsigned(n / 10);

    total += _putchar((n % 10) + '0');
    return (total);
}

/**
 * print_octal - Print unsigned int in octal
 * @n: number
 * Return: chars printed
 */
int print_octal(unsigned int n)
{
    int total = 0;

    if (n / 8)
        total += print_octal(n / 8);

    total += _putchar((n % 8) + '0');
    return (total);
}

/**
 * print_hex - Print unsigned int in hexadecimal
 * @n: number
 * @uppercase: flag (1 for A-F, 0 for a-f)
 * Return: chars printed
 */
int print_hex(unsigned int n, int uppercase)
{
    int total = 0;
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16)
        total += print_hex(n / 16, uppercase);

    total += _putchar(digits[n % 16]);
    return (total);
}
