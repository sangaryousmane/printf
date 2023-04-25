#include "main.h"

/**
 * _printf - Receive string and variable number of args
 * @format: Mandatory string at invocation
 * Return: counts of printed strings
 */
int _printf(const char *format, ...)
{
int character_to_print;
code_format format_list[] = {
{"d", print_int},
{"i", print_int},
{NULL, NULL},
};
va_list list_of_args;
if (format == NULL)
{
return (-1);
}
va_start(list_of_args, format);
character_to_print = format_receiver(format, format_list, list_of_args);
va_end(list_of_args);
return (character_to_print);
}
