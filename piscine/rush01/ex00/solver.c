/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgebrych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:00:33 by vgebrych          #+#    #+#             */
/*   Updated: 2026/07/26 18:05:59 by vgebrych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_duplicate(int *board, int size, int cell_pos, int try_value);
int	are_clues_broken(int *board, int size, int *clues, int cell_pos);

int	solve(int *board, int *clues, int size, int pos)
{
	int	try_value;

	try_value = 1;
	if (pos == size * size)
		return (1);
	while (try_value <= size)
	{
		if (board[pos] != 0)
			return (solve(board, clues, size, pos + 1));
		if (!is_duplicate(board, size, pos, try_value))
		{
			board[pos] = try_value;
			if (are_clues_broken(board, size, clues, pos)
				&& solve(board, clues, size, pos + 1))
				return (1);
			board[pos] = 0;
		}
		try_value++;
	}
	return (0);
}
