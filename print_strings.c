#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - handle the printing of char from arguments
 * @ap: pointer to arguments
 * Return: 1
 */
int print_char(va_list ap)
{
	_putchar(va_arg(ap, int));
	return (1);
}

/**
 * print_unknown - handle the printing of unkown
 * char with percent
 *
 * @c: The character to print
 * Return: 1
 */
int print_unknown(char c)
{
	return (_putchar(c));
}

/**
 * print_string - handle the printing of string from arguments
 * @ap:  pointer to arguments
 *
 * Return: length of string
 */
int print_string(va_list ap)
{
	int i = 0;
	char *str = va_arg(ap, char *);

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
