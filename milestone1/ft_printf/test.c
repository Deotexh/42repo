#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	// printf("Num with width of ten:\n %10d\n", 42);
	// printf("Num with precision of ten:\n %.10d\n", 42);
	// printf("\n");
	// printf("-Num with width of ten:\n %10d\n", -42);
	// printf("-Num with precision of ten:\n %.10d\n", -42);
	// printf("\n");
	// printf("Num with both:\n %10.10d\n", 42);
	// printf("\n");
	// printf("Num with width of eleven and precision of ten:\n %11.10d\n", 42);
	// printf("\n");
	// printf("Num with width of ten and flag 0:\n %010d\n", 42);
	// printf("Num with precision of ten and flag 0:\n %0.10d\n", 42);
	// printf("Num with width of eleven, precision of ten and flag 0:\n %011.10d\n", 42);
	// printf("\n");
	// printf("Num with width of ten and flag +:\n %+10d\n", 42);
	// printf("Num with precision of ten and flag +:\n %+.10d\n", 42);
	// printf("\n");
	// printf("Num with width of ten and flag -:\n %-10d\n", 42);
	// printf("Num with precision of ten and flag -:\n %-.10d\n", 42);
	// printf("\n");
	// printf("num with width of ten and flag ' ':\n % 10d\n", 42);
	// printf("num with precision of ten and flag ' ':\n % .10d\n", 42);
	// printf("\n");
	// printf("Num zero with plus ' ':\n %+d\n", 0);
	// printf("\n");
	// printf("num with width of ten and flag -:\n %-10d\n", 42);
	// printf("num with precision of ten and flag -:\n %-.10d\n", 42);
	// printf("\n");
	// printf("\n\n\n\n\n");
	char *str = "Bonjour %20s.\n";
	char *nbr = "Yoooo";
	ft_printf(str, nbr);
	printf(str, nbr);
}
