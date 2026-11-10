#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char *str = "Bonjour %20u.\n";
	void * value = (void *)255;
	ft_printf(str, value);
	printf(str, value);
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
