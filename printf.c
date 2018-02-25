#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "holberton.h"

int buffer_const_char(char **format, char *buffer, unsigned int *len)
{
	int printtotal = 0;
	while (**format != 0 && **format != '%')
	{
		buffer[(*len)++] = **format;
		(*format)++;
		if (*len == 1024)
		{
			write(1, buffer, 1024);
			*len = 0;
			printtotal += 1024;
		}
	}
	return (printtotal);
}

char *stringize_arg(va_list list, specifier spec, unsigned int *freeflag)
{
	static char tmpstr[2] = {0, 0};

	switch (spec.specifier)
	{
	case '%':
		tmpstr[0] = '%';
		return (tmpstr);
		break;
	case 'c':
		tmpstr[0] = (char) va_arg(list, int);
		return (tmpstr);
		break;
	case 's':
		*freeflag = 1;
		return (prep_string(va_arg(list, char *), spec));
		break;
	case 'd':
	case 'i':
		*freeflag = 1;
		return (prep_numeric(itos(list), spec));
		break;
	case 'b':
		*freeflag = 1;
		return (prep_numeric(uitob(list), spec));
		break;
	case 'u':
		*freeflag = 1;
		return (prep_numeric(utos(list), spec));
		break;
	case 'o':
		*freeflag = 1;
		return (prep_numeric(itoo(list), spec));
		break;
	case 'x':
		*freeflag = 1;
		return (prep_numeric(itox(list), spec));
		break;
	case 'X':
		*freeflag = 1;
		return (prep_numeric(itoX(list), spec));
	case 'r':
		*freeflag = 1;
		return (prep_string(rev(va_arg(list, char *)), spec));
	}
	return (NULL);
}

specifier get_specifier(char **format)
{
	specifier spec;
	char *start;

	start = *format;
	spec.left = 0, spec.sign = 0, spec.space = 0;
	spec.zerox = 0, spec.zero = 0;
	while (**format == '-' || **format == '+' || **format == ' '
	       || **format == '#' || **format == '0')
	{
		if (**format == '-')
			spec.left = 1;
		else if (**format == '+')
			spec.sign = 1;
		else if (**format == ' ')
			spec.space = 1;
		else if (**format == '#')
			spec.zerox = 1;
		else
			spec.zero = 1;
		(*format)++;
	}
	spec.width = 0;	spec.widthflag = 0;
	while (**format >= '0' && **format <= '9')
	{
		spec.widthflag = 1;
		spec.width *= 10;
		spec.width += **format - '0';
		(*format)++;
	}
	spec.precision = 1; spec.precisionflag = 0;
	if (**format == '.')
	{
		spec.precisionflag = 1;
		spec.precision = 0;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			spec.precision *= 10;
			spec.precision += **format - '0';
			(*format)++;
		}
	}
	spec.length = 0;
	while (**format == 'h')
	{
		(*format)++;
		spec.length--;
	}
	while (**format == 'l')
	{
		(*format)++;
		spec.length++;
	}
	spec.specifier = **format;
	switch (**format)
	{
	case '%': case 's': case 'c': case 'i': case 'd':
	case 'x': case 'X': case 'b': case 'o': case 'u':
	case 'r':
		(*format)++;
		break;
	default:
		*format = start;
		spec.specifier = '%';
		break;
	}
	return (spec);
}

int _printf(char *format, ...)
{
	char *tmp, *ptr, buffer[1024];
	unsigned int len = 0, freeflag = 0;
	unsigned long int printtotal = 0;
	va_list list;
	specifier spec;

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			spec = get_specifier(&format);
			freeflag = 0;
			tmp = stringize_arg(list, spec, &freeflag);
			ptr = tmp;
			while (*ptr)
			{
				buffer[len++] = *ptr++;
				if (len == 1024)
				{
					write(1, buffer, 1024);
					len = 0;
					printtotal += 1024;
				}
			}
			if (freeflag)
				free(tmp);
		}
		else
			printtotal += buffer_const_char(&format, buffer, &len);
	}
	write(1, buffer, len);
	printtotal += len;
	return (printtotal);
}
