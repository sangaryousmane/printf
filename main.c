#include <stdio.h>
#include <limits.h>
#include "main.h"

int _printf(const char *format, ...);
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
        len = _printf("Let's try to printf a simple sentence.\n");
        len2 = printf("Let's try to printf a simple sentence.\n");
        ui = (unsigned int)INT_MAX + 1024;
        _printf("Length:[%d, %i]\n", len, len);
        printf("Length:[%d, %i]\n", len2, len2);
        _printf("Negative:[%d]\n", -762534);
        printf("Negative:[%d]\n", -762534);
	_printf("%b\n", 98);
        _printf("Unsigned octal:[%o]\n", ui);
        printf("Unsigned octal:[%o]\n", ui);
        _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
        printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
        return (0);
}