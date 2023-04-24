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
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	len = _printf("Length:[%d, %i]\n", len, len);
	len2 = printf("Length:[%d, %i]\n", len2, len2);
	_printf("Length:[%d = %d]\n\n", len, len2);

	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);

	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

	len = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	_printf("Length:[%d = %d]\n\n", len, len2);

	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	_printf("Length:[%d = %d]\n\n", len, len2);

	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Length:[%d = %d]\n\n", len, len2);

	len = _printf("Unknown:[%r]\n");
	len2 = printf("Unknown:[%r]\n");
	_printf("Length:[%d = %d]\n\n", len, len2);

	return (0);
}
