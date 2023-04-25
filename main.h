#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* struct format_of_code - structure format
* @specifier: format specifier
* @associated_function: function associated with variable list
*/

typedef struct format_of_code
{
char *specifier;
int (*ass_func)(va_list);
} code_format;


/* internal*/
int _putchar(int c);
int format_receiver(const char *format, code_format format_list[], va_list argument_list);
int _printf(const char *format, ...);
int is_digit(char c);
int is_sign(char c);
int int_length(int num);
int print_int(va_list i);
#endif
