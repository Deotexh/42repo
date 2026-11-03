/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakhemkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:34:35 by kakhemkh          #+#    #+#             */
/*   Updated: 2026/07/26 20:10:20 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	validate_input(char *str, int num_of_clues);
void	parse_input(char *str, int num_of_clues, int *clues_arr);
int		*create_board(int board_size);
int		solve(int *board, int *clues, int size, int pos);
void	print_board(int *board, int size);

int	print_error(int error_code)
{
	write(1, "Error\n", 6);
	return (error_code);
}

int	init_game(char *str, int size, int **board, int **clues)
{
	int	num_of_clues;

	num_of_clues = size * 4;
	*clues = malloc(num_of_clues * sizeof(int));
	if (*clues == NULL)
		return (0);
	parse_input(str, num_of_clues, *clues);
	*board = create_board(size * size);
	if (*board == NULL)
	{
		free(*clues);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	size;
	int	*board;
	int	*clues;

	if (argc != 3)
		return (print_error());
	size = argv[2][0];
	else if ((argv[2][0] < '0' || argv[2][0] > '9') || argv[2][1] != '\0')
		return (print_error());
	else if (!validate_input(argv[1], size * 4))
		return (print_error());
	else if (!init_game(argv[1], size, &board, &clues))
		return (print_error());
	if (solve(board, clues, size, 0))
		print_board(board, size);
	else
		print_error();
	free(clues);
	free(board);
	return (0);
}
