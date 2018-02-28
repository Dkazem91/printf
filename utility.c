#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"
#include <unistd.h>
/**
 * _strlen - returns length of a string
 *
 * @str: string to get length of
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * _puts - prints a string followed by a newline
 *
 * @s: string to print;
 *
 * Return: number of characters printed
 */
int _puts(char *s)
{
	long int len;

	while (*s)
	{
		write(1, s, 1);
		len++;
		s++;
	}
	return (len);
}

/**
 * ifputs - checks if a prinft format string is puts
 *
 * @str: string to check
 *
 * Return: 1 if puts, 0 of not
 */
int ifputs(char *str)
{
	if (str[0] == '%' && str[1] == 's' && str[2] == '\n' && str[3] == 0)
		return (1);
	return (0);
}
