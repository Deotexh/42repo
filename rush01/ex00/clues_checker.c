int	is_row_full(int *board, int size, int row);
int	is_col_full(int *board, int size, int col);

int	check_lclue(int *board, int size, int *clue_arr, int row_pos)
{
	int	i;
	int	n_visible;
	int	cmp_value;

	i = -1;
	cmp_value = 0;
	n_visible = 0;
	while (++i < size)
	{
		if (board[i + (size * row_pos)] <= cmp_value)
			continue ;
		n_visible++;
		cmp_value = board[i + (size * row_pos)];
	}
	if (n_visible != clue_arr[row_pos + (size * 2)])
		return (0);
	return (1);
}

int	check_rclue(int *board, int size, int *clue_arr, int row_pos)
{
	int	i;
	int	n_visible;
	int	cmp_value;

	i = size;
	cmp_value = 0;
	n_visible = 0;
	while (--i >= 0)
	{
		if (board[i + (size * row_pos)] <= cmp_value)
			continue ;
		n_visible++;
		cmp_value = board[i + (size * row_pos)];
	}
	if (n_visible != clue_arr[row_pos + (size * 3)])
		return (0);
	return (1);
}

int	check_tclue(int *board, int size, int *clue_arr, int col_pos)
{
	int	i;
	int	n_visible;
	int	cmp_value;

	i = -1;
	cmp_value = 0;
	n_visible = 0;
	while (++i < size)
	{
		if (board[(i * size) + col_pos] <= cmp_value)
			continue ;
		n_visible++;
		cmp_value = board[(i * size) + col_pos];
	}
	if (n_visible != clue_arr[col_pos])
		return (0);
	return (1);
}

int	check_bclue(int *board, int size, int *clue_arr, int col_pos)
{
	int	i;
	int	n_visible;
	int	cmp_value;

	i = size;
	cmp_value = 0;
	n_visible = 0;
	while (--i >= 0)
	{
		if (board[(i * size) + col_pos] <= cmp_value)
			continue ;
		n_visible++;
		cmp_value = board[(i * size) + col_pos];
	}
	if (n_visible != clue_arr[col_pos + size])
		return (0);
	return (1);
}

int	are_clues_broken(int *board, int size, int *clue_arr, int cell_pos)
{
	int	row;
	int	col;

	row = cell_pos / size;
	col = cell_pos % size;
	if (is_row_full(board, size, row))
	{
		if (!check_lclue(board, size, clue_arr, row))
			return (0);
		if (!check_rclue(board, size, clue_arr, row))
			return (0);
	}
	if (is_col_full(board, size, col))
	{
		if (!check_bclue(board, size, clue_arr, col))
			return (0);
		if (!check_tclue(board, size, clue_arr, col))
			return (0);
	}
	return (1);
}
