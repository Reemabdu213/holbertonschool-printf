#include "main.h"
#include <stdlib.h>

#define BUF_SIZE 1024

static char buffer[BUF_SIZE];
static int buf_index;
static int flush_registered;

/**
 * flush_buffer - Flush the internal buffered output to stdout.
 */
void flush_buffer(void)
{
	if (buf_index > 0)
	{
		(void)write(1, buffer, buf_index);
		buf_index = 0;
	}
}

/**
 * _putchar - Queue a single character into a 1024-byte local buffer.
 * @c: Character to write.
 *
 * Return: Always 1.
 */
int _putchar(char c)
{
	if (!flush_registered)
	{
		atexit(flush_buffer);
		flush_registered = 1;
	}

	if (buf_index >= BUF_SIZE)
		flush_buffer();

	buffer[buf_index++] = c;
	return (1);
}
