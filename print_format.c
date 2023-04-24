#include "main.h"

/**
 * parse_signed_number - parse a signed number
 * @str: string to parse
 * @length: length of the token
 *
 * Return: the parsed number
 */
int parse_signed_number(const char *str, int *length)
{
	int sign = 1;
	int value = 0;

	*length = 0;

	/* (+|-)* */
	while (str[*length] == '+' || str[*length] == '-')
	{
		if (str[*length] == '-')
		{
			sign *= -1;
		}
		*length = *length + 1;
	}

	/* (0-9)* */
	while (str[*length] >= '0' && str[*length] <= '9')
	{
		value = value * 10 + str[*length] - '0';
		*length = *length + 1;
	}

	return (sign * value);
}

/**
 * print_formatted - print a value according to a format
 *
 * @current: format
 * @ap: arguments list
 *
 * Return: return 0 if not a formatted value else length of the string
 */
int print_formatted(const char *current, va_list ap, int *token_length)
{
	int length = 0;

	/* (+|-)*(0-9)* */
	if ((*current >= '0' && *current <= '9') || *current == '+' || *current == '-')
	{
		parse_signed_number(current, &length);
	}
	*token_length = length + 1;

	switch (*current)
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
		*token_length = 0;
		return (0);
	}
}
