#include "main.h"

/**
 * format_receiver - print formatted args
 * @format: mandatory chars
 * @args: List of all args
 * @lst: all args list
 * Return: total of printed values
 */

int format_receiver(const char *format, code_format lst[], va_list args)
{
int i, j, r_val, printables;
printables = 0;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
for (j = 0; lst[j].specifier != NULL; j++)
{
if (format[i + 1] == lst[j].specifier[0])
{
r_val = lst[j].ass_func(args);
if (r_val == -1)
return (-1);
printables += r_val;
break;
}
}
if (lst[j].specifier == NULL && format[i + 1] != ' ')
{
if (format[i + 1] != '\0')
{
_putchar(format[i]);
_putchar(format[i + 1]);
printables = printables + 2;
}
else
return (-1);
}
i = i + 1;
}
else
{
_putchar(format[i]);
printables++;
}
}
return (printables);
}

