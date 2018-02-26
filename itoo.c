#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"
char *itoo(va_list list)
{
	unsigned int digits, digitTest;
	int count, i;
	unsigned long mult, result;
	char* output;

	digits = va_arg(list, unsigned int);
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
	output = malloc(sizeof(char) * count + 1);
	mult /= 10;
        for (i = 0; i < count; i++)
        {
                output[i] = ((result / mult) + '0');
                result %= mult;
		mult /= 10;
        }
        output[i] = '\0';
	return(output);

}
