/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdockes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:25:26 by tdockes           #+#    #+#             */
/*   Updated: 2026/07/18 16:21:12 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_line(char l_edge, char middle, char r_edge, int loop_end)
{
	int	i;

	i = 1;
	ft_putchar(l_edge);
	while (i <= loop_end - 2)
	{
		ft_putchar(middle);
		++i;
	}
	if (loop_end > 1)
		ft_putchar(r_edge);
	ft_putchar('\n');
}
