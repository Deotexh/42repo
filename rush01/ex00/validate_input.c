int	validate_input(char *str, int num_of_clues)
{
	int i;
	int clue_counter;

	i = 0;
	clue_counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			clue_counter++;
		}
		else
			return (1);
		if (str[i] == '\0')
			break;
		else if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	if (clue_counter != num_of_clues)
		return (0);
	return (1);
}
