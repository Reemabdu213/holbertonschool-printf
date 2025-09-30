#include "main.h"

/**
 * print_char - Prints a character
 * @c: Character to print
 *
 * Return: Number of characters printed
 */
int print_char(char c)
{
	int count;

	count = _putchar(c);
	return (count);
}

/**
 * print_string - Prints a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
