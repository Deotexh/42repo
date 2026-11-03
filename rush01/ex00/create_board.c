/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgebrych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:07:04 by vgebrych          #+#    #+#             */
/*   Updated: 2026/07/26 16:48:02 by vgebrych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*create_board(int board_size)
{
	int	i;
	int	*board;

	board = malloc(board_size * sizeof(int));
	if (board == NULL)
		return (NULL);
	i = 0;
	while (i < board_size)
	{
		board[i] = 0;
		i++;
	}
	return (board);
}
