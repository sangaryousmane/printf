#include "main.h"
#include <unistd.h>
/**
 * size_convert - Casts a number to the specified n
 * @number: Number to be casted.
 * @n: Number indicating the type to be casted.
 *
 * Return: Casted value of number
 */
long int size_convert(long int number, int n)
{
if (n == 2)
{
return (number);
}
else if (n == 1)
{
return ((short)number);
}
return ((int)number);
}

/**
 * num_write - print a string
 * @neg: args list
 * @i: char types.
 * @b: handles buffer arrays
 * @flags: flags
 * @w: get width.
 * @p: specifier for p
 * @size: size
 *
 * Return: num of printable chars
 */
int num_write(int neg, int i, char b[], int flags, int w, int p, int size)
{
int len = BUFF_SIZE - i - 1;
char padding = ' ', char_ = 0;
UNUSED(size);
if ((flags & 4) && !(flags & 1))
{
padding = '0';
}
if (neg)
{
char_ = '-';
}
else if (flags & 2)
{
char_ = '+';
}
else if (flags & 16)
{
char_ = ' ';
}
return (write_num(i, b, flags, w, p, len, padding, char_));
}



/**
 * print_int - Print int
 * @tps: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active f
 * @w: get w.
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list tps, char b[], int f, int w, int p, int s)
{
int i = BUFF_SIZE - 2;
int isNeg = 0;
long int n = va_arg(tps, long int);
unsigned long int num;
n = size_convert(n, s);
if (n == 0)
{
b[i--] = '0';
}
b[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
isNeg = 1;
}
while (num > 0)
{
b[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (num_write(isNeg, i, b, f, w, p, s));
}


/**
 * is_digit - checks if character is a digit
 * @c:  character to be checked
 *
 * Return: 1 if digit, 0 otherwise
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * is_sign - checks if character is a sign
 * @c:  character to be checked
 *
 * Return: 1 if sign, 0 otherwise
 */
int is_sign(char c)
{
	return (c == '+' || c == '-');
}
