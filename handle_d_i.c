#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
* handle_print_d - handle the printing of decimal @d
* @d: decimal to be printed
* Return: size of @d
*/
int handle_print_d(va_list d)
{
int length, power, j, digit, n, counter, number;
counter = 0;
n = va_arg(d, int);
if (n != 0)
{
if (n < 0)
{
putchar('-');
counter++;
n *= -1;
}
number = n;
length = 0;
while (number != 0)
{
number /= 10;
length++;
}
power = 1;
j = 1;
while (j <= length - 1)
{
power *= 10;
j++;
}
j = 1;
while (j <= length)
{
digit = n / power;
putchar(digit + '0');
counter++;
n = n - (digit * power);
power /= 10;
j++;
}
}
else
{
putchar('0');
return (1);
}
return (counter);
}


/**
* handle_printing_i - handle the printing of integers @i
* @i: integer to be printed
* Return: size
*/
int handle_printing_i(va_list i)
{
int length, power, j, digit, n, counter, number;
counter = 0;
n = va_arg(i, int);
if (n != 0)
{
if (n < 0)
{
putchar('-');
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
{
power = power * 10;
}
for (j = 1; j <= length; j++)
{
digit = n / power;
if (n < 0)
{
putchar((digit * -1) + 48);
}
else
{
putchar(digit + '0');
}
counter++;
n -= (digit * power);
power /= 10;
}
}
else
{
putchar('0');
return (1);
}
return (counter);
}
