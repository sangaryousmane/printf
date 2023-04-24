#include <stdio.h>
#include "../main.h"

int main(void)
{
	int len, len2;
	len = printf("age: %c \n", 102);
	len2 = _printf("age: %c \n", 102);
	printf("%d = %d", len, len2);

	return (0);
}
