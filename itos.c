#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"
char *itos(va_list list)
{
        int digits, neg, count, i, mult;
	unsigned int digitTest, result;

	digits = va_arg(list, int);
	digitTest = digits;
	result = digits;
	neg = 0;
	if (digits < 0)
	{
		digitTest = -digits;
		result = -digits;
		neg = 1;
	}
	count = 0;
	mult = 1;
	while (digitTest > 0)
	{
		digitTest /= 10;
		count++;
		if(count > 1)
			mult *=10;
	}
	if (neg)
		count++;
	return (_numToString(result, count, mult, neg));
}
