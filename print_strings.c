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

