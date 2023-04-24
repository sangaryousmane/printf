#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* internal*/
int _putchar(int c);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);
int print_unknown(char c);
int print_formatted(const char *str, va_list ap, int *token_length);
int parse_signed_number(const char *str, int *length);
int int_length(int num);

int _printf(const char *format, ...);

#endif
