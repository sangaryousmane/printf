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
	while (is_sign(str[*length]))
	{
		if (str[*length] == '-')
		{
			sign *= -1;
		}
		*length = *length + 1;
	}

	/* (0-9)* */
	while (is_digit(str[*length]))
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
 * @token_length: length of the token
 *
 * Return: return 0 if not a formatted value else length of the string
 */
int print_formatted(const char *current, va_list ap, int *token_length)
{
	int length = 0;

	/* (+|-)*(0-9)* */

	*token_length = 0;
	if (is_digit(*current) || is_sign(*current))
	{
		parse_signed_number(current, &length);
		*token_length = length;
	}

	switch (current[*token_length])
	{
	case 'c':
		*token_length += 1;
		return (print_char(ap));
	case 's':
		*token_length += 1;
		return (print_string(ap));
	case 'd':
		*token_length += 1;
		return (print_int(ap));
	case 'i':
		*token_length += 1;
		return (print_int(ap));
	case '%':
		*token_length += 1;
		return (print_unknown('%'));

	default:
		*token_length = 0;
		return (0);
	}
}
