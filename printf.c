#include "main.h"

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
			switch (format[i])
			{
			case 'c':
				length += print_char(ap);
				break;
			case 's':

				length += print_string(ap);
				break;
			case 'd':
				length += print_int(ap);
				break;
			case 'i':
				length += print_int(ap);
				break;
			default:
				_putchar('%');
				_putchar(format[i]);
				length += 2;
				break;
			}
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
