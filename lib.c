#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(int c)
{
    return (write(1, &c, 1));
}

int int_length(int num)
{
    int length = 0;
    while (num != 0)
    {
        num /= 10;
        length++;
    }
    return length;
}

int print_int(va_list ap)
{
    int num = va_arg(ap, int);
    int length = int_length(num);
    int k, j;

    // array allocation
    char *array = malloc(length * sizeof(char));
    if (array == NULL)
    {
        return -1;
    }

    j = length - 1;

    // int to array
    while (j >= 0)
    {
        array[j] = (num % 10) + '0';
        num /= 10;
        j--;
    }

    // print array characters
    for (k = 0; k < length; k++)
    {
        _putchar(array[k]);
    }
    return length;
}

int print_char(va_list ap)
{
    _putchar(va_arg(ap, int));
    return 1;
}

int print_string(va_list ap)
{
    char *str = va_arg(ap, char *);
    int i = 0;
    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
    return i;
}

int _printf(const char *format, ...)
{
    va_list ap;
    int i = 0, length = 0;
    va_start(ap, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
            case 'c':
                length += print_char(ap);
                break;
            case 's':

                length += print_string(ap);
                break;
            case 'd':
                length += print_int(ap);
                break;
            case 'i':
                length += print_int(ap);
                break;
            default:
                _putchar('%');
                _putchar(format[i]);
                length += 2;
                break;
            }
        }
        else
        {
            _putchar(format[i]);
            length++;
        }
        i++;
    }

    va_end(ap);
    return length;
}
