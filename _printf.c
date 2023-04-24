#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * match_func - matching the printable format
 * @format: format to print
 * Return: a null value
 */
int (*match_func(const char *format))(va_list)
{
unsigned int i = 0;
format_of_code find_format[] = {
{"i", handle_print_i},
{"d", handle_print_d},
{NULL, NULL}
};
while (find_format[i].specifier)
{
if (find_format[i].specifier[0] == (*format))
{
return (find_format[i].ass_func);
}
i++;
}
return (NULL);
}

/**
 * _printf - Use the targeted format to produce an output
 * @format: format to print
 * Return: number length
 */
int _printf(const char *format, ...)
{
va_list num_list;
int (*match)(va_list);
int i = 0, length = 0;
if (format == NULL)
return (-1);
va_start(num_list, format);
while (format[i])
{
while (format[i] != '%' && format[i])
{
_putchar(format[i]);
length++;
i++;
}
if (format[i] == '\0')
return (length);
match = match_func(&format[i + 1]);
if (match)
{
length += match(num_list);
i += 2;
continue;
}
if (!format[i + 1])
{
return (-1);
}
_putchar(format[i]);
length++;
if (format[i + 1] == '%')
{
i += 2;
}
else
{
i++;
}
}
va_end(num_list);
return (length);
}
