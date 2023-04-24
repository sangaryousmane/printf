#ifndef PRINTFPROJECT
#define PRINTFPROJECT

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
int _putchar(int c);
int handle_print_d(va_list d);
int handle_print_i(va_list i);
int _printf(const char *format, ...);
/**
* struct format_of_code - structure format
* @specifier: format specifier
* @ass_func: function associated with variable list
*/

typedef struct format_of_code
{
char *specifier;
int (*ass_func)(va_list);
} code_format;

#endif
