#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"
char *itoo(va_list list)
{
	int digits, digitTest, count, i, mult, result;

	digits = va_arg(list, int);
	count = 0;
	mult = 1;
	result = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		result += (digitTest % 8) * mult;
		digitTest /= 8;
		mult *=10;
	        count++;
	}
	return (_numToString(result, count, (mult/10)));
}
