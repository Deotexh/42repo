/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdockes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:19:20 by tdockes           #+#    #+#             */
/*   Updated: 2026/07/18 16:21:41 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(char l_edge, char middle, char r_edge, int loop_end);

void	rush(int x, int y)
{
	int		pos_y;
	char	l_corner;
	char	r_corner;
	char	middle;

	pos_y = 0;
	while (pos_y++ <= y - 1)
	{
		middle = '*';
		l_corner = '/';
		r_corner = '\\';
		if (pos_y == y && y != 1)
		{
			l_corner = '\\';
			r_corner = '/';
		}
		else if (pos_y != y && pos_y != 1)
		{
			l_corner = '*';
			r_corner = '*';
			middle = ' ';
		}
		print_line(l_corner, middle, r_corner, x);
	}
}
