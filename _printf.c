#include "main.h"
/**
 *_printf - A simplified version of the standard printf function.
 *
 *@format: A string containing characters and format specifiers.
 *@...: the number of args.
 *
 *Return: The total number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
va_list arg;
int i = 0;
if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);
va_start(arg, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
return (-1);
if (*format == 'c')
i += _putchar(va_arg(arg, int));
else if (*format == 's')
i += print_string(va_arg(arg, char*));
else if (*format == '%')
i += _putchar('%');
else if (*format == 'd' || *format == 'i')
i += print_number(va_arg(arg, int));
else
{
i += _putchar('%');
i += _putchar(*format);
}
}
else
i += _putchar(*format);
format++;
}
va_end(arg);
return (i);
}
