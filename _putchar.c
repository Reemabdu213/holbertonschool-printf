#include "main.h"
#include <unistd.h>

/**
 * _putchar - write a character to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    ssize_t w;

    w = write(1, &c, 1);
    if (w != 1)
        return (-1);
    return (1);
}
