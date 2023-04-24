#include "main.h"

/**
 * print_formatted - print a value according to a format
 *
 * @current: format
 * @ap: arguments list
 * @token_length: length of the token
 *
 * Return: return 0 if not a formatted value else length of the string
 */
int print_formatted(const char *current, va_list ap, int *token_length)
{

	*token_length = 1;
	while (current[*token_length - 1])
	{
		switch (current[*token_length - 1])
		{
		case 'c':
			return (print_char(ap));

		case 's':
			return (print_string(ap));

		case 'd':
			return (print_int(ap));

		case 'i':
			return (print_int(ap));

		case '%':
			return (print_unknown('%'));

		default:
			*token_length += 1;
			break;
		}
	}
	*token_length = 0;
	return (0);
}
