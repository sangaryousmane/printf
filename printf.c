#include "main.h"

/**
 * _printf - Use the targeted format to produce an output
 * @format: format to print
 * Return: number length
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int length = 0;
	int i = 0, token_length;

	va_start(ap, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			token_length = 0;
			length += print_formatted(format + i + 1, ap, &token_length);
			i += token_length;
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
