/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:37:44 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/29 20:43:32 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	arg_i;
	int	char_i;

	arg_i = argc - 1;
	while (arg_i > 0)
	{
		char_i = 0;
		while (argv[arg_i][char_i] != '\0')
		{
			write(1, &argv[arg_i][char_i], 1);
			char_i++;
		}
		write(1, "\n", 1);
		arg_i--;
	}
}
