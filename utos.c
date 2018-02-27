#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"
char *utos(va_list list)
{
	unsigned int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, unsigned int);
	digitTest = digits;
	count = 0;
	while (digitTest > 0)
	{
		digitTest /= 10;
		count++;
	}
	digitTest = digits;
	result = malloc(sizeof(char) * count + 1);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}
char *lutos(va_list list)
{
	unsigned long int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, unsigned long int);
	digitTest = digits;
	count = 0;
	while (digitTest > 0)
	{
		digitTest /= 10;
		count++;
	}
	digitTest = digits;
	result = malloc(sizeof(char) * count + 1);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}
/*
char *llutos(va_list list)
{
	unsigned long long int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, unsigned long long int);
	digitTest = digits;
	count = 0;
	while (digitTest > 0)
	{
		digitTest /= 10;
		count++;
	}
	digitTest = digits;
	result = malloc(sizeof(char) * count + 1);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}
*/
char *hutos(va_list list)
{
	unsigned short int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, unsigned int);
	digitTest = digits;
	count = 0;
	while (digitTest > 0)
	{
		digitTest /= 10;
		count++;
	}
	digitTest = digits;
	result = malloc(sizeof(char) * count + 1);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}

char *hhutos(va_list list)
{
	unsigned char digits, digitTest;
	int count, i;
	char *result;

	digits = (unsigned char) va_arg(list, unsigned int);
	digitTest = digits;
	count = 0;
	while (digitTest > 0)
	{
		digitTest /= 10;
		count++;
	}
	digitTest = digits;
	result = malloc(sizeof(char) * count + 1);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}
