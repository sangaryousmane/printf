#include "main.h"
#include <unistd.h>
/**
 * print_buffer -prints buffer
 * @buffer: strings
 * @index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *index)
{
if (*index > 0)
{
write(1, &buffer[0], *index);
}
*index = 0;
}

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;
if (format[curr_i] == 'l')
size = 2;
else if (format[curr_i] == 'h')
size = 1;
if (size == 0)
*i = curr_i - 1;
else
*i = curr_i;
return (size);
}

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
int j, start;
int f = 0;
const char CHAR_FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
const int ARGS_FLAGS[] = {1, 2, 4, 8, 16, 0};
for (start = *i + 1; format[start] != '\0'; start++)
{
for (j = 0; CHAR_FLAGS[j] != '\0'; j++)
{
if (format[start] == CHAR_FLAGS[j])
{
f |= ARGS_FLAGS[j];
break;
}
if (CHAR_FLAGS[j] == 0)
{
break;
}
}
*i = start - 1;
}
return (f);
}




/**
 * _printf - Printf function
 * @format: formatter
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int f, width, precision, size, index = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[index++] = format[i];
if (index == BUFF_SIZE)
print_buffer(buffer, &index);
printed_chars++;
}
else
{
print_buffer(buffer, &index);
f = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
printed = formatter(format, &i, list, buffer, f, width, precision, size);
if (printed == -1)
{
return (-1);
}
printed_chars += printed;
}
}

print_buffer(buffer, &index);
va_end(list);
return (printed_chars);
}
