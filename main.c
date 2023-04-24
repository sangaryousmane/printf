#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;

	len = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	_printf("Length:[%d = %d]\n\n", len, len2);

	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	_printf("Length:[%d = %d]\n\n", len, len2);

	len = _printf("Unknown:[%r]\n");
	len2 = printf("Unknown:[%r]\n");
	_printf("Length:[%d = %d]\n\n", len, len2);

	len = _printf("String:[%s]\n", NULL);
	len2 = printf("String:[%s]\n", NULL);
	_printf("Length:[%d = %d]\n\n", len, len2);

	return (0);
}
