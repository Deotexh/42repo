/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdockes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:19:20 by tdockes           #+#    #+#             */
/*   Updated: 2026/07/18 16:21:32 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(char l_edge, char middle, char r_edge, int loop_end);

void	rush(int x, int y)
{
	int		pos_y;
	char	corner;
	char	middle;

	pos_y = 0;
	while (pos_y++ <= y - 1)
	{
		if ((pos_y == 1 || pos_y == y))
		{
			corner = 'o';
			middle = '-';
		}
		else
		{
			corner = '|';
			middle = ' ';
		}
		print_line(corner, middle, corner, x);
	}
}
