#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* internal*/
int _putchar(int c);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);
int print_unknown(char c);
int print_value(char c, va_list ap);
int int_length(int num);

int _printf(const char *format, ...);

#endif
