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
	const char *format;

	format = "Character:[%c]\n";
	len = _printf(format, 'H');
	len2 = printf(format, 'H');
	printf("%d = %d\n\n", len, len2);

	format = "String:[%s]\n";
	len = _printf(format, "I am a string !");
	len2 = printf(format, "I am a string !");
	printf("%d = %d\n\n", len, len2);

	format = "Unknown:[%r]\n";
	len = _printf(format);
	len2 = printf(format);
	printf("%d = %d\n\n", len, len2);

	format = "%s%r%1\n";
	len = _printf(format, NULL);
	len2 = printf(format, NULL);
	printf("%d = %d\n\n", len, len2);

	return (0);
}
