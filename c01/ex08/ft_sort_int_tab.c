/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:45:38 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/20 14:55:24 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	vi_lomuto_partition(int *tab, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	i = start - 1;
	j = start;
	pivot = tab[end];
	while (j < end)
	{
		if (tab[j] < pivot)
		{
			++i;
			ft_swap(tab + j, tab + i);
		}
		++j;
	}
	ft_swap(tab + i + 1, tab + end);
	return (i + 1);
}

void	vi_quicksort(int *tab, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = vi_lomuto_partition(tab, start, end);
	vi_quicksort(tab, start, pivot - 1);
	vi_quicksort(tab, pivot + 1, end);
}

void	ft_sort_int_tab(int *tab, int size)
{
	vi_quicksort(tab, 0, size - 1);
}

/*
#include <stdio.h>
int	 main()
{
	int tabTest[11] = {933, -12, 2, 48, 6, 1, 645, 3, 6, 3, 12};
	ft_sort_int_tab(tabTest, 11);

	int i = 0;
	while (i < 11)
	{
		printf("First element %d is: %d\n", i + 1, tabTest[i]);
		++i;
	}
}
*/
