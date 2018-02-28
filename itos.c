#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"
/**
 * itos - converts integer to string
 * @list: variadic argument
 * Return: a string
 */
char *itos(va_list list)
{
	int digits, count, i, neg, absMod, digitTest;
	char *output;

	digits = va_arg(list, int);
	digitTest = digits;
	count = 0;
	neg = 0;
	if (digits < 0)
	{
		neg = 1;
		count++;
	}
	while (digitTest != 0)
	{
		digitTest /= 10;
		count++;
	}
	output = malloc(sizeof(char) * count + 1);
	if (output == NULL)
		return (NULL);
	if (neg)
		output[0] = '-';
	digitTest = digits;
	for (i = count - 1; i >= 0 + neg; i--)
	{
		absMod = digitTest % 10;
		output[i] = (absMod < 0 ? -absMod : absMod) + '0';
		digitTest /= 10;
	}
	output[count] = '\0';
	return (output);

}
/**
 * litos - converts integer to string (long)
 * @list: variadic argument
 * Return: a string
 */
char *litos(va_list list)
{
	int count, i, neg, absMod;
	long int digits, digitTest;
	char *output;

	digits = va_arg(list, long int);
	digitTest = digits;
	count = 0;
	neg = 0;
	if (digits < 0)
	{
		neg = 1;
		count++;
	}
	while (digitTest != 0)
	{
		digitTest /= 10;
		count++;
	}
	output = malloc(sizeof(char) * count + 1);
	if (output == NULL)
		return (NULL);
	if (neg)
		output[0] = '-';
	digitTest = digits;
	for (i = count - 1; i >= 0 + neg; i--)
	{
		absMod = digitTest % 10;
		output[i] = (absMod < 0 ? -absMod : absMod) + '0';
		digitTest /= 10;
	}
	output[count] = '\0';
	return (output);

}
/**
 * hitos - converts integer to string (short)
 * @list: variadic argument
 * Return: a string
 */
char *hitos(va_list list)
{
	int count, i, neg, absMod;
	short int digits, digitTest;
	char *output;

	digits = va_arg(list, int);
	digitTest = digits;
	count = 0;
	neg = 0;
	if (digits < 0)
	{
		neg = 1;
		count++;
	}
	while (digitTest != 0)
	{
		digitTest /= 10;
		count++;
	}
	output = malloc(sizeof(char) * count + 1);
	if (output == NULL)
		return (NULL);
	if (neg)
		output[0] = '-';
	digitTest = digits;
	for (i = count - 1; i >= 0 + neg; i--)
	{
		absMod = digitTest % 10;
		output[i] = (absMod < 0 ? -absMod : absMod) + '0';
		digitTest /= 10;
	}
	output[count] = '\0';
	return (output);

}
/**
 * hhitos - converts integer to string (short short)
 * @list: variadic argument
 * Return: a string
 */
char *hhitos(va_list list)
{
	int count, i, neg, absMod;
	char digits, digitTest;
	char *output;

	digits = (char) va_arg(list, int);
	digitTest = digits;
	count = 0;
	neg = 0;
	if (digits < 0)
	{
		neg = 1;
		count++;
	}
	while (digitTest != 0)
	{
		digitTest /= 10;
		count++;
	}
	output = malloc(sizeof(char) * count + 1);
	if (output == NULL)
		return (NULL);
	if (neg)
		output[0] = '-';
	digitTest = digits;
	for (i = count - 1; i >= 0 + neg; i--)
	{
		absMod = digitTest % 10;
		output[i] = (absMod < 0 ? -absMod : absMod) + '0';
		digitTest /= 10;
	}
	output[count] = '\0';
	return (output);

}
