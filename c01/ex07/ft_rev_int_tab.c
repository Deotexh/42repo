/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:45:38 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/19 12:55:00 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp_int;
	int	half_size;

	i = 0;
	half_size = size;
	if (half_size % 2 == 1)
		--half_size;
	half_size /= 2;
	while (i < half_size)
	{
		temp_int = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp_int;
		++i;
	}
}

/*
#include <stdio.h>
int	 main()
{
	int tabTest[11] = {2, 48, 6, 1, 645, 3, 6, 3, 12};
	ft_rev_int_tab(tabTest, 11);

	int i = 0;
	while (i < 11)
	{
		printf("Index %d is: %d\n", i, tabTest[i]);
		++i;
	}
}
*/
