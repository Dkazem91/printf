#include "holberton.h"
#include <stdlib.h>

/**
 * rev - reverses a string
 *
 * @str: string to reverse
 *
 * Return: reversed string
 */
char *rev(char *str)
{
	long int i = 0, len;
	char tmp, *ret, *ptr;

	if (str == NULL)
		return (null());
	len = _strlen(str);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
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
/**
 * rot - converts to rot 13 encryption
 * @str: string to conver
 * Return: returns a string
 */
char *rot(char *str)
{
	char input[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char key[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	long int i, j, len;
	char *copy;

	if (str == NULL)
		return (null());
	len = _strlen(str);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	copy[len] = 0;
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	for (i = 0; i < len; i++)
	{
		for (j = 0; input[j] != '\0'; j++)
		{
			if (copy[i] == input[j])
			{
				copy[i] = key[j];
				break;
			}
		}
	}

	return (copy);
}
/**
 * print_hidden - prints full string and non printable chars
 * @str: string to convert
 * Return: converted string
 */
char *print_hidden(char *str)
{
	char *output, *ptr;
	long int i, len = 0;

	if (str == NULL)
		return (null());
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
			len += 3;
		len++;
	}
	output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	for (ptr = output; *str; str++)
	{
		if (*str < 32 || *str >= 127)
		{
			*ptr++ = '\\';
			*ptr++ = 'x';
			*ptr++ = *str / 16 > 9 ? (*str / 16) + 55 : (*str / 16) + '0';
			*ptr++ = *str % 16 > 9 ? (*str % 16) + 55 : (*str % 16) + '0';
		}
		else
			*ptr++ = *str;
	}
	*ptr = 0;
	return (output);
}

/**
 * null - returns the string "(null)", dynamically allocated
 *
 * Return: output string
 */
char *null()
{
	char *ret, *ptr;
	char *null = "(null)";

	ret = malloc(7 * sizeof(char));
	ptr = ret;
	while (*null)
		*ptr++ = *null++;
	*ptr = 0;
	return (ret);
}
