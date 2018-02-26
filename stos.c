#include "holberton.h"
#include <stdlib.h>

/**
 * rev - reverses a string
 *
 * @str - string to reverse
 *
 * Return: reversed string
 */
char *rev(char *str)
{
	int i = 0, len;
	char tmp, *ret, *ptr;

	len = _strlen(str);
	ret = malloc(len + 1);
	ret[len] = 0;
	ptr = ret;
	while (*str)
		*ptr++ = *str++;
	len--;
	while (i < len)
	{
		tmp = ret[i];
		ret[i++] = ret[len];
		ret[len--] = tmp;
	}
	return (ret);
}
char *rot(char *str)
{
	char input[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char key[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j, len;
	char *ret;

	len = _strlen(str);
	ret = malloc(sizeof(char) * (len + 1));
	for (i = 0; i < len; i++)
	{
		for (j = 0; input[j] != '\0'; j++)
		{
			if(str[i] == input[j])
				str[i] = key[j];
		}
		ret[i] = str[i];
	}
	ret[i] = '\0';

	return (ret);
}
