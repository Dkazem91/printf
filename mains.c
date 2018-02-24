#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"
int _printf(char *, ...);

int main(void)
{
	char arr[2000];
	int i=1999;
	arr[1999] = 0;
	while (i--)
		arr[i] = 'a';
	printf("FROM MAIN: %.3s\n", arr);
	return _printf("%b\n", 98);
}
