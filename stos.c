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
	char *copy;

	len = _strlen(str);
	copy = malloc(sizeof(char) * (len + 1));
	copy[len] = 0;
	i = 0;
	while(str[i])
	{
		copy[i] = str[i];
		i++;
	}
	for (i = 0; i < len; i++)
	{
		for (j = 0; input[j] != '\0'; j++)
		{
			if(copy[i] == input[j])
			{
				copy[i] = key[j];
				break;
			}
		}
	}

	return (copy);
}

char *print_hidden(char *str)
{
	char *output, *ptr;
	int i, len = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
			len += 3;
		len++;
	}
	output = malloc (sizeof(char) * (len + 1));
	for (ptr = output; *str; str++)
	{
		if (*str < 32 || *str >= 127)
		{
			*ptr++ = '\\';
			*ptr++ = 'x';
			*ptr++ = *str / 16 > 9 ? (*str / 16) + 55:(*str / 16) + '0';
			*ptr++ = *str % 16 > 9 ? (*str % 16) + 55:(*str % 16) + '0';
		}
		else
			*ptr++ = *str;
	}
	*ptr = 0;
	return (output);
}
