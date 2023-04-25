#include "main.h"
/**
 * formatter - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @l: List of arguments to be printed.
 * @ind: ind.
 * @b: Buffer array to handle print.
 * @f: Calculates active f
 * @w: get w.
 * @p: Precision specification
 * @s: Size specifier
 * Return: 1 or 2;
 */
int formatter(const char *format, int *ind,
va_list l, char b[], int f, int w, int p, int s)
{
int i, u_len = 0, printables = -1;
code_format f_types[] = {
{'i', print_int},
{'d', print_int},
{'\0', NULL}
};
for (i = 0; f_types[i].specifier != '\0'; i++)
if (format[*ind] == f_types[i].specifier)
return (f_types[i].ass_func(l, b, f, w, p, s));

if (f_types[i].specifier == '\0')
{
if (format[*ind] == '\0')
return (-1);
u_len += write(1, "%%", 1);
if (format[*ind - 1] == ' ')
{
u_len += write(1, " ", 1);
}
else if (w)
{
--(*ind);
while (format[*ind] != ' ' && format[*ind] != '%')
{
--(*ind);
}
if (format[*ind] == ' ')
--(*ind);
return (1);
}
u_len += write(1, &format[*ind], 1);
return (u_len);
}
return (printables);
}
