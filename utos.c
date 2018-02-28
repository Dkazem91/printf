#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"
/**
 * utos - convertes unsigned to string
 * @list: list of vargs to take
 * Return: returns a string
 */
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
	if (result == NULL)
		return (NULL);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}

/**
 * lutos - convertes unsigned to string (long)
 * @list: list of vargs to take
 * Return: returns a string
 */
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
	if (result == NULL)
		return (NULL);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}

/**
 * hutos - convertes unsigned to string (short)
 * @list: list of vargs to take
 * Return: returns a string
 */
char *hutos(va_list list)
{
	unsigned short int digits, digitTest;
	int count, i;
	char *result;

	digits = (unsigned short) va_arg(list, unsigned int);
	digitTest = digits;
	count = 0;
	while (digitTest > 0)
	{
		digitTest /= 10;
		count++;
	}
	digitTest = digits;
	result = malloc(sizeof(char) * count + 1);
	if (result == NULL)
		return (NULL);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}

/**
 * hhutos - convertes unsigned to string (short short)
 * @list: list of vargs to take
 * Return: returns a string
 */
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
	if (result == NULL)
		return (NULL);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}
