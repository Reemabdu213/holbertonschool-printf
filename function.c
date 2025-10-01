#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	ssize_t w;

	w = write(1, &c, 1);
	return (w == 1 ? 1 : -1);
}

/**
 * print_string - prints a string
 * @str: string to print
 *
 * Return: number of characters printed, or -1 on error
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		if (_putchar(*str) == -1)
			return (-1);
		count++;
		str++;
	}
	return (count);
}

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		if (_putchar('-') == -1)
			return (-1);
		count++;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
	{
		int w = print_number(num / 10);

		if (w == -1)
			return (-1);
		count += w;
	}
	if (_putchar((num % 10) + '0') == -1)
		return (-1);
	count++;
	return (count);
}
