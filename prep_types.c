#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>

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
	char fill = ' ';

	if (spec.specifier == 'b' || spec.specifier == 'x'
	    || spec.specifier == 'X')
		xtype = 1;
	if (spec.zero == 1 && spec.left == 0)
		fill = '0';

	digits = _strlen(str);
	len = digits;
	if (len < spec.precision && spec.precisionflag == 1)
		len = spec.precision;
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
		spec.width -= len;
		len += spec.width;
	}
	else
		spec.width = 0;

	ret = malloc((len + 1) * sizeof(char));
	ptr = ret;
	if (spec.zerox == 1 && (spec.zero == 1 || spec.left == 1) && *str)
	{
		*ptr++ = '0';
		if (xtype)
			*ptr++ = spec.specifier;
	}
	while (spec.left == 0 && spec.width--)
		*ptr++ = fill;
	if (spec.zerox == 1 && spec.zero == 0 && spec.left == 0 &&
	    (*str))
	{
		*ptr++ = '0';
		if (xtype)
			*ptr++ = spec.specifier;
	}
	while (spec.precision-- > digits)
		*ptr++ = '0';
	while (digits--)
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

	len = _strlen(str);
	if (len > spec.precision && spec.precisionflag == 1)
		len = spec.precision;

	if (len < spec.width && spec.widthflag == 1)
	{
		ret = malloc((spec.width + 1) * sizeof(char));
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
		ptr = ret;
		while (len--)
			*ptr++ = *str++;
		*ptr = 0;
	}
	if (spec.specifier != 's')
		free(hold);
	return (ret);
}
