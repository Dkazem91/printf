#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"
char *itox(va_list list)
{
	unsigned int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, unsigned int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /= 16;
	        count++;
	}

	result = malloc(sizeof(char) * count + 1);
	digitTest = digits;
	for (i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}

char *litox(va_list list)
{
	unsigned long int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, long int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /= 16;
		count++;
	}

	result = malloc(sizeof(char) * count + 1);
	digitTest = digits;
	for (i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}

/*char *llitox(va_list list)
{
	unsigned long long int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, long long int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /=16;
	        count++;
	}

	result = malloc(sizeof(char) * count + 1);
	digitTest = digits;
	for(i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}
*/
char *hitox(va_list list)
{
	short int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /= 16;
		count++;
	}

	result = malloc(sizeof(char) * count + 1);
	digitTest = digits;
	for(i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}

/*
char *hhitox(va_list list)
{
	char digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, char);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /=16;
	        count++;
	}

	result = malloc(sizeof(char) * count + 1);
	digitTest = digits;
	for(i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}
*/
