#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * prep_numeric - prepares a numeric string for printf
 *
 * @str: numeric string to prepare
 * @spec: specifier info
 *
 * Return: char * to new string
 */
char *prep_numeric(char *str, specifier spec)
{
	char *ret, *ptr, *hold = str;
	unsigned int len, digits, xtype = 0;
	char fill = ' ', sign = 0;

	if (str == NULL)
	{
		free(hold);
		return (NULL);
	}
	if (spec.specifier == 'p' && *str == 0)
	{
		free(hold);
		return (nil());
	}
	if (spec.specifier == 'b' || spec.specifier == 'x' ||
	    spec.specifier == 'X' || spec.specifier == 'p')
		xtype = 1;
	if (spec.specifier == 'p')
		spec.specifier = 'x';
	digits = _strlen(str);
	len = digits;
	if (spec.zero == 1 && spec.left == 0 && spec.precisionflag == 0)
		fill = '0';

	if (*str == '-')
	{
		str++;
		sign = '-';
		digits--;
		len--;
	}
	else if (spec.sign == 1 && (spec.specifier == 'd' || spec.specifier == 'i'))
	{
		sign = '+';
	}
	else if (spec.space == 1 && (spec.specifier == 'd' || spec.specifier == 'i'))
	{
		sign = ' ';
	}
	if (len < spec.precision)
		len = spec.precision;
	if (sign)
		len++;
	if (spec.zerox == 1 && xtype == 1)
		len += 2;
	else if (spec.zerox == 1 && spec.specifier == 'o')
	{
		if (spec.precision <= digits)
			spec.precision = digits + 1;
		len = spec.precision;
		spec.zerox = 0;
	}
	else
		spec.zerox = 0;
	if (spec.width > len)
	{
		if (spec.precision == len && sign)
			spec.width--;
		spec.width -= len;
		len += spec.width;
	}
	else
		spec.width = 0;

	if (sign)
		len++;
	ret = malloc((len + 1) * sizeof(char));
	if (ret == NULL)
	{
		free(hold);
		return (NULL);
	}
	ptr = ret;
	if (spec.zerox == 1 && (fill == '0' || spec.left == 1) && *str)
	{
		*ptr++ = '0';
		if (xtype)
			*ptr++ = spec.specifier;
	}
	if (fill == '0' && sign)
		*ptr++ = sign;
	while (spec.left == 0 && spec.width--)
		*ptr++ = fill;
	if (fill == ' ' && spec.zerox == 1 && spec.left == 0 && (*str))
	{
		*ptr++ = '0';
		if (xtype)
			*ptr++ = spec.specifier;
	}
	if (fill != '0' && sign)
		*ptr++ = sign;
	while (spec.precision-- > digits)
		*ptr++ = '0';
	while (*str)
		*ptr++ = *str++;
	while (spec.left == 1 && spec.width--)
		*ptr++ = ' ';
	*ptr = 0;
	free(hold);
	return (ret);
}

/**
 * prep_string - prepares a character string for printf
 *
 * @str: string to prepare
 * @spec: specifier info
 *
 * Return: char * to new string
 */
char *prep_string(char *str, specifier spec)
{
	char *ret, *ptr, *hold = str;
	unsigned int len;

	if (str == NULL)
	{
		if (spec.specifier != 's' && spec.specifier != 'c')
			free(hold);
		return (null());
	}
	len = _strlen(str);
	if (spec.specifier == 'c' && *str == 0)
		len++;
	if (len > spec.precision && spec.precisionflag == 1)
		len = spec.precision;

	if (len < spec.width && spec.widthflag == 1)
	{
		ret = malloc((spec.width + 1) * sizeof(char));
		if (ret == NULL)
		{
			if (spec.specifier != 's' && spec.specifier != 'c')
				free(hold);
			return (NULL);
		}
		ptr = ret;
		if (spec.left == 0)
		{
			while (len < spec.width--)
				*ptr++ = ' ';
			while (len--)
				*ptr++ = *str++;
			*ptr = 0;
		}
		else
		{
			spec.width -= len;
			while (len--)
				*ptr++ = *str++;
			while (spec.width--)
				*ptr++ = ' ';
			*ptr = 0;
		}
	}
	else
	{
		ret = malloc((len + 1) * sizeof(char));
		if (ret == NULL)
		{
			if (spec.specifier != 's' && spec.specifier != 'c')
				free(hold);
			return (NULL);
		}
		ptr = ret;
		while (len--)
			*ptr++ = *str++;
		*ptr = 0;
	}
	if (spec.specifier != 's' && spec.specifier != 'c')
		free(hold);
	return (ret);
}
