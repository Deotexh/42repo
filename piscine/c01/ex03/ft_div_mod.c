/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:45:38 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/19 11:34:07 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>
int	main()
{
	int	x = 10;
	int y = 3;
	int div;
	int mod;

	ft_div_mod(x, y, &div, &mod);
	printf("%d / %d = %d, with remainder: %d", x, y, div, mod);
}
*/
