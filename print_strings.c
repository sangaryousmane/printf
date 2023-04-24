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
 * _putstring - writes the string str to stdout
 * @str: The string to print
 *
 * Return: On success returns the length of the string.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstring(char *str)
{
	int length = 0;

	while (str[length])
	{
		length++;
	}
	return write(1, str, length);
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
	char *str = va_arg(ap, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	return _putstring(str);
}
