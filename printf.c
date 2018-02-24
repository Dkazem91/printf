#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void buffer_const_char(char **format, char *buffer, unsigned int *len)
{
		while (**format != 0 && **format != '%')
		{
			buffer[(*len)++] = **format;
			(*format)++;
		}
}

char *stringize_arg(va_list list, char *format)
{
	static char tmpstr[2] = {0, 0};

	switch (*format)
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
		return (va_arg(list, char *));
	}
	return (NULL);
}

int _printf(char *format, ...)
{
	char *tmp, buffer[1024];
	unsigned int len = 0, bufflen = 0;
	unsigned long int printtotal = 0;
	va_list list;

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp = stringize_arg(list, format);
			format++;
			while (*tmp)
				buffer[len++] = *tmp++;
		}
		else
			buffer_const_char(&format, buffer, &len);
	}
	write(1, buffer, len);
	printtotal += len;
	return (printtotal);
}
