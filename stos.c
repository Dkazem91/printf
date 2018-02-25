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
