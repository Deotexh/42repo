/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:57:39 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/15 20:51:57 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	int		i;
	char	current_char;

	i = 0;
	while (i <= 25)
	{
		current_char = 'a' + i;
		write(1, &current_char, 1);
		++i;
	}
}
