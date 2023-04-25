#include <unistd.h>
#include "main.h"
/**
* _putchar - write @c to stdout
* @c: the character*
* Return: On success 1.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
