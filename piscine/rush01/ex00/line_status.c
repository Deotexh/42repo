int	is_row_full(int *board, int size, int row)
{
	int	col;

	col = 0;
	while (col < size)
	{
		if (board[row * size + col] == 0)
			return (0);
		col++;
	}
	return (1);
}

int	is_col_full(int *board, int size, int col)
{
	int	row;

	row = 0;
	while (row < size)
	{
		if (board[row * size + col] == 0)
			return (0);
		row++;
	}
	return (1);
}
