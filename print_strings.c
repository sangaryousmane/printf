#include "main.h"

int _putchar(int c)
{
    return (write(1, &c, 1));
}

int print_char(va_list ap)
{
    _putchar(va_arg(ap, int));
    return (1);
}

int print_string(va_list ap)
{
    int i = 0;
    char *str = va_arg(ap, char *);

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
    return (i);
}
