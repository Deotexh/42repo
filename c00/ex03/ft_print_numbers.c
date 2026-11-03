/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:57:39 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/15 20:53:00 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	int		i;
	char	current_char;

	i = 0;
	while (i <= 9)
	{
		current_char = '0' + i;
		write(1, &current_char, 1);
		++i;
	}
}
