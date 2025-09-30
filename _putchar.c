#include "main.h"

/**
 * _putchar - writes one character to stdout
 * @c: character to print
 *
 * Return: bytes written on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
