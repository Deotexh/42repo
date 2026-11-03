/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:48:42 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/18 15:47:56 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	cycle_comb( int init_pos, int end_pos, char *num_ref, int size)
{
	int	index;
	int	position;

	position = init_pos;
	while (position <= end_pos)
	{
		if ((num_ref[(size - 1) - (9 - end_pos)]) != 0 && end_pos == 9)
			write(1, ", ", 2);
		num_ref[(size - 1) - (9 - end_pos)] = position + '0';
		if (end_pos == 9)
		{
			index = -1;
			while (++index < size)
			{
				ft_putchar(num_ref[index]);
			}
		}
		else
			cycle_comb(position + 1, end_pos + 1, num_ref, size);
		++position;
	}
}

void	ft_print_combn(int n)
{
	char	num[9];

	if (n <= 0 || n >= 10)
		return ;
	num[n - 1] = 0;
	cycle_comb(0, 10 - n, num, n);
}
