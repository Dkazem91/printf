#include <stdlib.h>
/**
 * nil - returns the string "(nil)", dynamically allocated
 *
 * Return: output string
 */
char *nil()
{
	char *ret, *ptr;
	char *nil = "(nil)";

	ret = malloc(6 * sizeof(char));
	ptr = ret;
	while (*nil)
		*ptr++ = *nil++;
	*ptr = 0;
	return (ret);
}
