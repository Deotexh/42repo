/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgebrych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:08:49 by vgebrych          #+#    #+#             */
/*   Updated: 2026/07/26 14:10:27 by vgebrych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_duplicate(int *board, int size, int pos, int try_value)
{
	int	row;
	int	column;
	int	row_end;
	int	first_row_pos;
	int	first_col_pos;

	row = pos / size;
	column = pos % size;
	first_row_pos = row * size;
	first_col_pos = column;
	row_end = first_row_pos + size;
	while (first_row_pos < row_end)
	{
		if (board[first_row_pos] == try_value)
			return (1);
		first_row_pos++;
	}
	while (first_col_pos < size * size)
	{
		if (board[first_col_pos] == try_value)
			return (1);
		first_col_pos = first_col_pos + size;
	}
	return (0);
}
