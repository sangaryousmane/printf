#include "main.h"
/**
* write_num - Write a number using a bufffer
* @ct: Index at which the number starts on the buffer
* @b: Buffer
* @f: Flags
* @w: width
* @p: Precision specifier
* @l: Number len
* @pad: Pading char
* @c: Extra char
*
* Return: Number of printed chars.
*/

int write_num(int ct, char b[], int f, int w, int p, int l, char pad, char c)
{
int i = 1, padd_start = 1;
if (p == 0 && ct == BUFF_SIZE - 2 && b[ct] == '0' && w == 0)
{
return (0);
}
if (p == 0 && ct == BUFF_SIZE - 2 && b[ct] == '0')
{
b[ct] = pad = ' ';
}
if (p > 0 && p < l)
{
pad = ' ';
}
while (p > l)
{
b[--ct] = '0', l++;
}
if (c != 0)
{
l++;
}
return (helper(ct, b, f, w, l, pad, c, i, padd_start));
}



/**
 * helper - Write a number using a bufffer
 * @ct: Index at which the number starts on the buffer
 * @b: Buffer
 * @f: Flags
 * @w: width
 * @p: Precision specifier
 * @l: Number len
 * @p: Pading char
 * @c: Extra char
 * @s: start
 * @i: initial counter
 * Return: Number of printed chars.
 */
int helper(int ct, char b[], int f, int w, int l, char p, char c, int i, int s)
{
if (w > l)
{
for (i = 1;  i < w - l + 1; i++)
{
b[i] = p;
}
b[i] = '\0';
if (f & 1 && p == ' ')
{
if (c)
b[--ct] = c;
return (write(1, &b[ct], l) + write(1, &b[1], i - 1));
}
else if (!(f & 1) && p == ' ')
{
if (c)
b[--ct] = c;
return (write(1, &b[1], i - 1) + write(1, &b[ct], l));
}
else if (!(f & 1) && p == '0')
{
if (c)
{
b[--s] = c;
}
return (write(1, &b[s],  i - s) + write(1, &b[ct], l - (1 - s)));
}
}
if (c)
b[--ct] = c;
return (write(1, &b[ct], l));
}
