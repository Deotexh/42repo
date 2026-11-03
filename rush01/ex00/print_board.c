/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgebrych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:16:30 by vgebrych          #+#    #+#             */
/*   Updated: 2026/07/26 12:19:02 by vgebrych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int *board, int size)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			c = board[row * size + col] + '0';
			write(1, &c, 1);
			if (col < size - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			col++;
		}
		row++;
	}
}
