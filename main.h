#ifndef PRINTFPROJECT
#define PRINTFPROJECT

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
int _putchar(int c);
int _puts(char *s);
int handle_print_d(va_list d);
int handle_print_i(va_list i);

/**
* struct format_of_code - structure format
* @specifier: format specifier
* @associated_function: function associated with variable list
*/

typedef struct format_of_code
{
char *specifier;
int (*associated_function)(va_list);
} code_format;

#endif;


