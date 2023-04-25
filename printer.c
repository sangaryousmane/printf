#include "main.h"

/**
 * get_fmt - gets the format function based on the type
 * @char: formatter type
 * Return: the formatter function;
 */
formatter *get_fmt(char s)
{
	switch (s)
	{
	case 'c':
		return (print_char);
	case 's':
		return (print_string);
	case '%':
		return (print_percent);
	case 'i':
	case 'd':
		return (print_int);
	case 'b':
		return (print_binary);
	case 'u':
		return (print_unsigned);
	case 'o':
		return (print_octal);
	case 'x':
		return (print_hexadecimal);
	case 'X':
		return (print_hexa_upper);
	case 'p':
		return (print_pointer);
	case 'S':
		return (print_non_printable);
	case 'r':
		return (print_reverse);
	case 'R':
		return (print_rot13string);
	default:
		return (NULL);
	}
}

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
				 int flags, int width, int precision, int size)
{
	int unknow_len = 0, printed_chars = -1;
	formatter *print = get_fmt(fmt[*ind]);

	if (print != NULL)
		return ((*print)(list, buffer, flags, width, precision, size));
	else
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
