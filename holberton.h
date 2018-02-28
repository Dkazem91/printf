#ifndef HOLBERTONH
#define HOLBERTONH
#include <stdarg.h>

/**
 * struct specifier - contains specifiers for printf
 *
 * @width: width of field to print
 * @precision: precision of field to print
 * @length: modifies type length. h/l flags. 0 default, +1 per l, -1 per h
 * @widthflag: tells whether width is set
 * @precisionflag: tells whether precision is set
 * @left: left justify, '-'. 0 for right, 1 for left
 * @sign: force sign, '+'. 0 for no, 1 for yes
 * @space: space pad left side of positive numbers if leading 0s. 0 no 1 yes
 * @zero: zero pad numbers up to width. 0 for no, 1 for yes.
 * @zerox: add leading 0, 0x, or 0X to o, x or X specifiers. 0 no 1 yes
 * @specifier: the data type to print, c, s, d, x, etc.
 */
typedef struct specifier
{
	unsigned int width;
	unsigned int precision;
	int length;
	char widthflag;
	char precisionflag;
	char left;
	char sign;
	char space;
	char zero;
	char zerox;
	char specifier;
} specifier;

/* from printf.c */
int _printf(char *format, ...);

/* from prep_types.c */
char *prep_string(char *str, specifier spec);
char *prep_numeric(char *str, specifier spec);

/* from utility.c */
int _strlen(char *str);
int ifputs(char *s);

/* from itos.c */
char *itos(va_list list);
char *hitos(va_list list);
char *litos(va_list list);
char *hhitos(va_list list);

/* from uitob.c */
char *uitob(va_list list);
char *luitob(va_list list);
char *huitob(va_list list);
char *hhuitob(va_list list);

/* from utos.c */
char *utos(va_list list);
char *hutos(va_list list);
char *hhutos(va_list list);
char *lutos(va_list list);

/* from itoo.c */
char *itoo(va_list list);
char *litoo(va_list list);
char *hitoo(va_list list);
char *hhitoo(va_list list);

/* from itox.c */
char *itox(va_list list);
char *litox(va_list list);
char *hitox(va_list list);
char *hhitox(va_list list);

/* from itox.c */
char *itoX(va_list list);
char *hitoX(va_list list);
char *hhitoX(va_list list);
char *litoX(va_list list);

/* from stos.c */
char *rev(char *str);
char *rot(char *str);
char *print_hidden(char *str);
char *null(void);

/* from ptos.c */
char *nil(void);

#endif
