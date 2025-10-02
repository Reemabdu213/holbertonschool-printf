#include "main.h"
#include <unistd.h>

#define BUF_SIZE 1024

static char buffer[BUF_SIZE];
static int buf_index;

/**
 * flush_buffer - write all buffered characters to stdout
 */
void flush_buffer(void)
{
	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
		buf_index = 0;
	}
}

/**
 * _putchar - buffered write of one character to stdout
 * @c: character to print
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
	if (buf_index >= BUF_SIZE)
		flush_buffer();

	buffer[buf_index++] = c;
	return (1);
}
