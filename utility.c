#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"
int _strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}
char * _numToString(int result, int count, int chop)
{
	int i;
	char *output;

	output = malloc(sizeof(char) * count + 1);
	for (i = 0; i < count; i++)
	{
		output[i] = ((result / chop) + '0');
		result %= chop;
		chop /= 10;
	}
	output[i] = '\0';
	return(output);
}
