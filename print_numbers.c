#include "main.h"

/**
 * int_length - returns the number of digits of @num
 * @num: integer will be used to calculate its number of digits
 * Return: number of digits
 */
int int_length(int num)
{
	int length = 0;

	while (num != 0)
	{
		num /= 10;
		length++;
	}
	return (length);
}

/**
 * print_int - handle the printing of integers @i
 * @ap: pointer to arguments
 * Return: size
 */
int print_int(va_list ap)
{
	int num = va_arg(ap, int);
	int length = int_length(num);
	int k, j;

	/* array allocation */
	char *array = malloc(length * sizeof(char));

	if (array == NULL)
	{
		return (-1);
	}

	j = length - 1;

	/* int to array */
	while (j >= 0)
	{
		array[j] = (num % 10) + '0';
		num /= 10;
		j--;
	}

	/* print array characters */
	for (k = 0; k < length; k++)
	{
		_putchar(array[k]);
	}
	return (length);
}
