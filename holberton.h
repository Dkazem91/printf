#ifndef HOLBERTONH
#define HOLBERTONH

/**
 * specifier - contains specifiers for printf
 *
 * @width: width of field to print
 * @precision: precision of field to print
 * @length: modifies type length. h/l flags.
 * @left: left justify, '-'. 0 for right, 1 for left
 * @sign: force sign, '+'. 0 for no, 1 for yes
 * @space: space pad left side of positive numbers if leading 0s. 0 no 1 yes
 * @zero: zero pad numbers up to width. 0 for no, 1 for yes.
 * @zerox: add leading 0, 0x, or 0X to o, x or X specifiers. 0 no 1 yes
 */
typedef struct specifier
{
	int width;
	int precision;
	int length;
	char left;
	char sign;
	char space;
	char zero;
	char zerox;
} specifier;

#endif
