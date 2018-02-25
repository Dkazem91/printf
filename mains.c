#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"
#include <limits.h>

int _printf(char *, ...);

int main(void)
{
	char arr[2000];
	int i=1999;

	setbuf(stdout, NULL);
	arr[1999] = 0;
	while (i--)
		arr[i] = 'a';
	_printf("Formatting and min/max tests\n");
	printf("%%60s:%60s\n", "A helpful string that is 49 chars long.");
	_printf("%%60s:%60s\n", "A helpful string that is 49 chars long.");
	printf("%%-60s:%-60s\n", "A helpful string that is 49 chars long.");
	_printf("%%-60s:%-60s\n", "A helpful string that is 49 chars long.");
	printf("%s%d\n", "Int max d:", INT_MAX);
	_printf("%s%d\n", "Int max d:", INT_MAX);
	printf("%s%30d\n", "Int max 30d:", INT_MAX);
	_printf("%s%30d\n", "Int max 30d:", INT_MAX);
	printf("%s%-30d\n", "Int max -30d:", INT_MAX);
	_printf("%s%-30d\n", "Int max -30d:", INT_MAX);
	printf("%s%-030d\n", "Int max -030d:", INT_MAX);
	_printf("%s%-030d\n", "Int max -030d:", INT_MAX);
	printf("%s%030d\n", "Int max 030d:", INT_MAX);
	_printf("%s%030d\n", "Int max 030d:", INT_MAX);
	printf("%s%#030d\n", "Int max #030d:", INT_MAX);
	_printf("%s%#030d\n", "Int max #030d:", INT_MAX);
	printf("%s%#.0d\n", "Int max #.0d:", INT_MAX);
	_printf("%s%#.0d\n", "Int max #.0d:", INT_MAX);
	printf("%s%d\n", "Int 0 d:", 0);
	_printf("%s%d\n", "Int 0 d:", 0);
	printf("%s%.0d\n", "Int 0 .0d:", 0);
	_printf("%s%.0d\n", "Int 0 .0d:", 0);
	printf("%s%0.0d\n", "Int 0 0.0d:", 0);
	_printf("%s%0.0d\n", "Int 0 0.0d:", 0);
	printf("%s%#.0d\n", "Int 0 #.0d:", 0);
	_printf("%s%#.0d\n", "Int 0 #.0d:", 0);
	printf("%s%#0.0d\n", "Int 0 #0.0d:", 0);
	_printf("%s%#0.0d\n", "Int 0 #0.0d:", 0);
	printf("%s%#.1d\n", "Int 0 #.1d:", 0);
	_printf("%s%#.1d\n", "Int 0 #.1d:", 0);
	printf("%s%#.20d\n", "Int max #.20d:", INT_MAX);
	_printf("%s%#.20d\n", "Int max #.20d:", INT_MAX);
	printf("%s%#-.20d\n", "Int max #-.20d:", INT_MAX);
	_printf("%s%#-.20d\n", "Int max #-.20d:", INT_MAX);
	printf("%s%#30.20d\n", "Int max #30.20d:", INT_MAX);
	_printf("%s%#30.20d\n", "Int max #30.20d:", INT_MAX);
	printf("%s%-#30.20d\n", "Int max -#30.20d:", INT_MAX);
	_printf("%s%-#30.20d\n", "Int max -#30.20d:", INT_MAX);
	printf("%s%-#020.20d\n", "Int max -#020.20d:", INT_MAX);
	_printf("%s%-#020.20d\n", "Int max -#020.20d:", INT_MAX);
	printf("%s%u\n", "UInt max u:", UINT_MAX);
	_printf("%s%u\n", "UInt max u:", UINT_MAX);
	printf("%s%30u\n", "UInt max 30u:", UINT_MAX);
	_printf("%s%30u\n", "UInt max 30u:", UINT_MAX);
	printf("%s%-30u\n", "UInt max -30u:", UINT_MAX);
	_printf("%s%-30u\n", "UInt max -30u:", UINT_MAX);
	printf("%s%-030u\n", "UInt max -030u:", UINT_MAX);
	_printf("%s%-030u\n", "UInt max -030u:", UINT_MAX);
	printf("%s%030u\n", "UInt max 030u:", UINT_MAX);
	_printf("%s%030u\n", "UInt max 030u:", UINT_MAX);
	printf("%s%#030u\n", "UInt max #030u:", UINT_MAX);
	_printf("%s%#030u\n", "UInt max #030u:", UINT_MAX);
	printf("%s%#.0u\n", "UInt max #.0u:", UINT_MAX);
	_printf("%s%#.0u\n", "UInt max #.0u:", UINT_MAX);
	printf("%s%#.0u\n", "UInt 0 #.0u:", 0);
	_printf("%s%#.0u\n", "UInt 0 #.0u:", 0);
	printf("%s%#0.0u\n", "UInt 0 #0.0u:", 0);
	_printf("%s%#0.0u\n", "UInt 0 #0.0u:", 0);
	printf("%s%.0u\n", "UInt 0 .0u:", 0);
	_printf("%s%.0u\n", "UInt 0 .0u:", 0);
	printf("%s%u\n", "UInt 0 u:", 0);
	_printf("%s%u\n", "UInt 0 u:", 0);
	printf("%s%#.20u\n", "UInt max #.20u:", UINT_MAX);
	_printf("%s%#.20u\n", "UInt max #.20u:", UINT_MAX);
	printf("%s%#-.20u\n", "UInt max #-.20u:", UINT_MAX);
	_printf("%s%#-.20u\n", "UInt max #-.20u:", UINT_MAX);
	printf("%s%#30.20u\n", "UInt max #30.20u:", UINT_MAX);
	_printf("%s%#30.20u\n", "UInt max #30.20u:", UINT_MAX);
	printf("%s%-#30.20u\n", "UInt max -#30.20u:", UINT_MAX);
	_printf("%s%-#30.20u\n", "UInt max -#30.20u:", UINT_MAX);
	printf("%s%-#030.20u\n", "UInt max -#030.20u:", UINT_MAX);
	_printf("%s%-#030.20u\n", "UInt max -#030.20u:", UINT_MAX);
	printf("%s%-#020.20u\n", "UInt max -#020.20u:", UINT_MAX);
	_printf("%s%-#020.20u\n", "UInt max -#020.20u:", UINT_MAX);
	_printf("%s%b\n", "UInt max b:", UINT_MAX);
	_printf("%s%40b\n", "UInt max 40b:", UINT_MAX);
	_printf("%s%40b\n", "UInt max .20b:", UINT_MAX);
	_printf("%s%.0b\n", "Int 0 .0b:", 0);
	_printf("%s%0.0b\n", "Int 0 0.0b:", 0);
	_printf("%s%#.0b\n", "Int 0 #.0b:", 0);
	_printf("%s%#0.0b\n", "Int 0 #0.0b:", 0);
	_printf("%s%#40b\n", "UInt max #40b:", UINT_MAX);
	_printf("%s%-40b\n", "UInt max -40b:", UINT_MAX);
	_printf("%s%040b\n", "UInt max 040b:", UINT_MAX);
	_printf("%s%0.40b\n", "UInt max 0.40b:", UINT_MAX);
	_printf("%s%040.20b\n", "UInt max 040.20b:", UINT_MAX);
	_printf("%s%040.40b\n", "UInt max 040.40b:", UINT_MAX);
	_printf("%s%040.60b\n", "UInt max 040.60b:", UINT_MAX);
	_printf("%s%-#40b\n", "UInt max -#40b:", UINT_MAX);
	_printf("%s%-0#40b\n", "UInt max -0#40b:", UINT_MAX);
	_printf("%s%-0#40.20b\n", "UInt max -0#40.20b:", UINT_MAX);
	printf("%s%x\n", "Int max x:", INT_MAX);
	_printf("%s%x\n", "Int max x:", INT_MAX);
	printf("%s%30x\n", "Int max 30x:", INT_MAX);
	_printf("%s%30x\n", "Int max 30x:", INT_MAX);
	printf("%s%-30x\n", "Int max -30x:", INT_MAX);
	_printf("%s%-30x\n", "Int max -30x:", INT_MAX);
	printf("%s%-030x\n", "Int max -030x:", INT_MAX);
	_printf("%s%-030x\n", "Int max -030x:", INT_MAX);
	printf("%s%030x\n", "Int max 030x:", INT_MAX);
	_printf("%s%030x\n", "Int max 030x:", INT_MAX);
	printf("%s%#030x\n", "Int max #030x:", INT_MAX);
	_printf("%s%#030x\n", "Int max #030x:", INT_MAX);
	printf("%s%#.0x\n", "Int max #.0x:", INT_MAX);
	_printf("%s%#.0x\n", "Int max #.0x:", INT_MAX);
	printf("%s%#0.0x\n", "Int max #0.0x:", INT_MAX);
	_printf("%s%#0.0x\n", "Int max #0.0x:", INT_MAX);
	printf("%s%.0x\n", "Int 0 .0x:", 0);
	_printf("%s%.0x\n", "Int 0 .0x:", 0);
	printf("%s%0.0x\n", "Int 0 0.0x:", 0);
	_printf("%s%0.0x\n", "Int 0 0.0x:", 0);
	printf("%s%x\n", "UInt 0 x:", 0);
	_printf("%s%x\n", "UInt 0 x:", 0);
	printf("%s%#.0x\n", "Int 0 #.0x:", 0);
	_printf("%s%#.0x\n", "Int 0 #.0x:", 0);
	printf("%s%#.20x\n", "Int max #.20x:", INT_MAX);
	_printf("%s%#.20x\n", "Int max #.20x:", INT_MAX);
	printf("%s%#-.20x\n", "Int max #-.20x:", INT_MAX);
	_printf("%s%#-.20x\n", "Int max #-.20x:", INT_MAX);
	printf("%s%#30.20x\n", "Int max #30.20x:", INT_MAX);
	_printf("%s%#30.20x\n", "Int max #30.20x:", INT_MAX);
	printf("%s%-#30.20x\n", "Int max -#30.20x:", INT_MAX);
	_printf("%s%-#30.20x\n", "Int max -#30.20x:", INT_MAX);
	printf("%s%-#020.20x\n", "Int max -#020.20x:", INT_MAX);
	_printf("%s%-#020.20x\n", "Int max -#020.20x:", INT_MAX);
	printf("%s%X\n", "Int max X:", INT_MAX);
	_printf("%s%X\n", "Int max X:", INT_MAX);
	printf("%s%30X\n", "Int max 30X:", INT_MAX);
	_printf("%s%30X\n", "Int max 30X:", INT_MAX);
	printf("%s%-30X\n", "Int max -30X:", INT_MAX);
	_printf("%s%-30X\n", "Int max -30X:", INT_MAX);
	printf("%s%-030X\n", "Int max -030X:", INT_MAX);
	_printf("%s%-030X\n", "Int max -030X:", INT_MAX);
	printf("%s%030X\n", "Int max 030X:", INT_MAX);
	_printf("%s%030X\n", "Int max 030X:", INT_MAX);
	printf("%s%#030X\n", "Int max #030X:", INT_MAX);
	_printf("%s%#030X\n", "Int max #030X:", INT_MAX);
	printf("%s%#.0X\n", "Int max #.0X:", INT_MAX);
	_printf("%s%#.0X\n", "Int max #.0X:", INT_MAX);
	printf("%s%.0X\n", "Int 0 .0X:", 0);
	_printf("%s%.0X\n", "Int 0 .0X:", 0);
	printf("%s%0.0X\n", "Int 0 0.0X:", 0);
	_printf("%s%0.0X\n", "Int 0 0.0X:", 0);
	printf("%s%X\n", "UInt 0 X:", 0);
	_printf("%s%X\n", "UInt 0 X:", 0);
	printf("%s%#.0X\n", "Int 0 #.0X:", 0);
	_printf("%s%#.0X\n", "Int 0 #.0X:", 0);
	printf("%s%#0.0X\n", "Int 0 #0.0X:", 0);
	_printf("%s%#0.0X\n", "Int 0 #0.0X:", 0);
	printf("%s%#.20X\n", "Int max #.20X:", INT_MAX);
	_printf("%s%#.20X\n", "Int max #.20X:", INT_MAX);
	printf("%s%#-.20X\n", "Int max #-.20X:", INT_MAX);
	_printf("%s%#-.20X\n", "Int max #-.20X:", INT_MAX);
	printf("%s%#30.20X\n", "Int max #30.20X:", INT_MAX);
	_printf("%s%#30.20X\n", "Int max #30.20X:", INT_MAX);
	printf("%s%-#30.20X\n", "Int max -#30.20X:", INT_MAX);
	_printf("%s%-#30.20X\n", "Int max -#30.20X:", INT_MAX);
	printf("%s%-#030.20X\n", "Int max -#030.20X:", INT_MAX);
	_printf("%s%-#030.20X\n", "Int max -#030.20X:", INT_MAX);
	printf("%s%-#020.20X\n", "Int max -#020.20X:", INT_MAX);
	_printf("%s%-#020.20X\n", "Int max -#020.20X:", INT_MAX);
	#define INT_MAX 12341234
	printf("%s%o\n", "Int max o:", INT_MAX);
	_printf("%s%o\n", "Int max o:", INT_MAX);
	printf("%s%30o\n", "Int max 30o:", INT_MAX);
	_printf("%s%30o\n", "Int max 30o:", INT_MAX);
	printf("%s%-30o\n", "Int max -30o:", INT_MAX);
	_printf("%s%-30o\n", "Int max -30o:", INT_MAX);
	printf("%s%-030o\n", "Int max -030o:", INT_MAX);
	_printf("%s%-030o\n", "Int max -030o:", INT_MAX);
	printf("%s%030o\n", "Int max 030o:", INT_MAX);
	_printf("%s%030o\n", "Int max 030o:", INT_MAX);
	printf("%s%#030o\n", "Int max #030o:", INT_MAX);
	_printf("%s%#030o\n", "Int max #030o:", INT_MAX);
	printf("%s%#.0o\n", "Int max #.0o:", INT_MAX);
	_printf("%s%#.0o\n", "Int max #.0o:", INT_MAX);
	printf("%s%#0.0o\n", "Int max #0.0o:", INT_MAX);
	_printf("%s%#0.0o\n", "Int max #0.0o:", INT_MAX);
	printf("%s%.0o\n", "Int 0 .0o:", 0);
	_printf("%s%.0o\n", "Int 0 .0o:", 0);
	printf("%s%0.0o\n", "Int 0 0.0o:", 0);
	_printf("%s%0.0o\n", "Int 0 0.0o:", 0);
	printf("%s%o\n", "UInt 0 o:", 0);
	_printf("%s%o\n", "UInt 0 o:", 0);
	printf("%s%#.0o\n", "Int 0 #.0o:", 0);
	_printf("%s%#.0o\n", "Int 0 #.0o:", 0);
	printf("%s%#.20o\n", "Int max #.20o:", INT_MAX);
	_printf("%s%#.20o\n", "Int max #.20o:", INT_MAX);
	printf("%s%#-.20o\n", "Int max #-.20o:", INT_MAX);
	_printf("%s%#-.20o\n", "Int max #-.20o:", INT_MAX);
	printf("%s%#30.20o\n", "Int max #30.20o:", INT_MAX);
	_printf("%s%#30.20o\n", "Int max #30.20o:", INT_MAX);
	printf("%s%-#30.20o\n", "Int max -#30.20o:", INT_MAX);
	_printf("%s%-#30.20o\n", "Int max -#30.20o:", INT_MAX);
	printf("%s%-#030.20o\n", "Int max -#030.20o:", INT_MAX);
	_printf("%s%-#030.20o\n", "Int max -#030.20o:", INT_MAX);
	printf("%s%-#020.20o\n", "Int max -#020.20o:", INT_MAX);
	_printf("%s%-#020.20o\n", "Int max -#020.20o:", INT_MAX);
	/* Put other test cases here */
	_printf("Other test cases\n");
	printf("%zzzzzs%s\n", "--case %zzzzzs%s--");
	_printf("%zzzzzs%s\n", "--case %zzzzzs%s--");
	printf("%123zzzzzs%s\n", "--case %123zzzzzs%s--");
	_printf("%123zzzzzs%s\n", "--case %123zzzzzs%s--");
	printf("%99999999999s\n", "A really wide string");
}
