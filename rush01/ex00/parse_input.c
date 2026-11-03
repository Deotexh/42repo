void	parse_input(char *str, int num_of_clues, int *clues_arr)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while(++j < num_of_clues)
	{
		clues_arr[j] = str[i] - '0';
		i += 2;
	}
}
