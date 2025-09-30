#include "main.h"

/**
 * _printf - print formatted data to the standard output
 *
 * @format: format string containing conversion specifiers
 *
 * Description: the _printf function parses the format string and processes
 *              each conversion specifier by calling the appropriate function
 *              to print the corresponding data type. Additional arguments
 *              after @format are retrieved using va_list and va_start to
 *              access the variable arguments. The function returns the total
 *              number of characters printed.
 *
 * Return: -1 if format is NULL
 *         the number of characters printed (the total length string)
 */

int _printf(const char *format, ...)
{
	int index_format = 0;
	int total_length = 0;

	va_list arguments;

	va_start(arguments, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

	/* loop through the format string to process each character */
	while (format[index_format] != '\0')
	{
		if (format[index_format] == '%')
		{
			/**
			 * if a '%' is found,
			 * call specifiers_handler to process the conversion specifier
			 */
			total_length += specifiers_handler(format[index_format + 1], arguments);
			/* move to the next character after the conversion specifier */
			index_format += 2;
		}
		else
		{
			/**
			 * if it's not a '%',
			 * directly print the character and update the total_length
			 */
			total_length += _putchar(format[index_format]);
			index_format++;
		}
	}

	va_end(arguments);

	return (total_length);
}				
