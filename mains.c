#include <stdarg.h>
int _printf(char *, ...);

int main(void)
{
	return _printf("Hello%%%c%s\n", 'c', " a string appears! ");
}
