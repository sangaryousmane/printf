#ifndef MAIN_H
#define MAIN_H

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* struct format_of_code - structure format
* @specifier: format specifier
* @ass_func: function associated with variable list
*/

typedef struct format_of_code
{
char specifier;
int (*ass_func)(va_list, char[], int, int, int, int);
} code_format;


/* internal*/
int _putchar(int c);
int _printf(const char *format, ...);
int formatter(const char *format, int *ind,
va_list l, char b[], int f, int w, int p, int s);
int is_digit(char c);
int is_sign(char c);
int int_length(int num);
int print_int(va_list tps, char b[], int f, int w, int p, int s);
int write_num(int ct, char b[], int f, int w, int p,
int l, char pad, char c);
int helper(int ct, char b[], int f, int w, int l, char p,
char c, int i, int s);
int num_write(int neg, int i, char b[], int f, int w, int p, int s);
void print_buffer(char buffer[], int *buff_ind);
int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
#endif
