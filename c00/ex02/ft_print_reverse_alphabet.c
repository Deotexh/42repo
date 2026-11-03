/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:46:34 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/15 20:52:32 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int		i;
	char	current_char;

	i = 0;
	while (i <= 25)
	{
		current_char = 'z' - i;
		write(1, &current_char, 1);
		++i;
	}
}
