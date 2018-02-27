#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
 * _strlen - returns length of a string
 *
 * @str: string to get length of
 *
 * Return: length of string
 */
long int _strlen(char *str)
{
	long int len = 0;

	while (*str++)
		len++;

	return (len);
}
