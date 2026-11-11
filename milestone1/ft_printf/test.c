#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char *str = "%p";
	char *value = "Bonjour";
	int result1 = ft_printf(str, value);
	int result2 = printf(str, value);

	printf("\n\nMine:\t\t%d\nOriginal:\t%d\n", result1, result2);
}

/*
 Who accepts which flags (all not undefined):
 p => {-}
 c => {-}
 s => {-.}
 x/X => {#-0.}
 i/d => {+- 0.}
 u => {-0.}
 */
