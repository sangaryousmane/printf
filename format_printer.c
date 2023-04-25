#include "main.h"

/**
* format_receiver - Receive and print all parameters as formatted string
* @format: Consist all chars
* @fmt_lst: A list of all the posible functions.
* @args: all args list
* Return: sum of printed characters
*/
int format_receiver(const char *format, code_format fmt_lst[], va_list args)
{
int i, j, received_value, character_to_print;
character_to_print = 0;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
for (j = 0; fmt_lst[j].specifier != NULL; j++)
{
if (format[i + 1] == fmt_lst[j].specifier[0])
{
received_value = fmt_lst[j].ass_func(args);
if (received_value == -1)
return (-1);
character_to_print += received_value;
break;
}
}
if (fmt_lst[j].specifier == NULL && format[i++] != ' ')
{
if (format[i++] != '\0')
{
_putchar(format[i]);
_putchar(format[i++]);
character_to_print += 2;
}
else
return (-1);
}
i += 1;
}
else
{
_putchar(format[i]);
character_to_print += 1;
}
}
return (character_to_print);
}

