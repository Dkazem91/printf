#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * prep_string - prepares a string for printf
 *
 * @str: string to prepare
 * @spec: specifier info
 *
 * Return: char * to new string
 */
char *prep_string(char *str, specifier spec)
{
	char *ret, *ptr;
	unsigned int len, tmp;

	len = _strlen(str);
/*	printf("In prep_string precision %s / %d / %d\n",str, len, spec.precision);*/
	if (len > spec.precision && spec.precisionflag != 0)
		len = spec.precision;

	printf("In prep_string width %d / %s\n", spec.width, str);
	if (spec.width > spec.precision && spec.precisionflag != 0)
		spec.width = spec.precision;
	if (len < spec.width && spec.width > spec.precision && spec.widthflag != 0)
	{
		ret = malloc((spec.width + 1) * sizeof(char));
		ptr = ret;
		if (spec.left == 0)
		{
			printf("In left just\n");
			while (len < spec.width--)
				*ptr++ = ' ';
			while (len--)
				*ptr++ = *str++;
		}
		else
		{
			printf("In right just\n");
			spec.width -= len;
			while (len--)
				*ptr++ = *str++;
			while (spec.width--)
				*ptr++ = ' ';
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
	return (ret);
}
