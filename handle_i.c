#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
* handle_printing_i - handle the printing of integers @i
* @i: integer to be printed
* Return: size
*/
int handle_print_i(va_list i)
{
int length, power, j, digit, n, counter, number;
counter = 0;
n = va_arg(i, int);
if (n != 0)
{
if (n < 0)
{
_putchar('-');
counter++;
}
number = n;
length = 0;
while (number != 0)
{
number /= 10;
length++;
}
power = 1;
for (j = 1; j <= length - 1; j++)
power = power * 10;
for (j = 1; j <= length; j++)
{
digit = n / power;
if (n < 0)
{
_putchar((digit * -1) + 48);
}
else
_putchar(digit + '0');
counter++;
n -= digit * power;
power /= 10;
}
}
else
{
_putchar('0');
return (1);
}
return (counter);
}
