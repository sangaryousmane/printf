#include "main.h"

/**
 * print_value - print a value according to a format
 *
 * @c: format
 * @ap: arguments list
 *
 * Return: length of the string
 */
int print_value(char c, va_list ap)
{
	switch (c)
	{
	case 'c':
		return print_char(ap);
	case 's':
		return print_string(ap);

	case 'd':
		return print_int(ap);
	case 'i':
		return print_int(ap);

	default:
		return print_unknown(c);
	}
}

/**
 * _printf - Use the targeted format to produce an output
 * @format: format to print
 * Return: number length
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, length = 0;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			length += print_value(format[i], ap);
		}
		else
		{
			_putchar(format[i]);
			length++;
		}
		i++;
	}

	va_end(ap);
	return (length);
}
