/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:21:39 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/15 20:34:59 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void)
{
	int		left_number;
	int		right_number;
	char	result[5];

	left_number = 00;
	result[2] = ' ';
	while (left_number < 99)
	{
		right_number = left_number + 1;
		result[0] = (left_number / 10) + '0';
		result[1] = (left_number % 10) + '0';
		while (right_number < 100)
		{
			if (left_number == right_number)
				continue ;
			result[3] = (right_number / 10) + '0';
			result[4] = (right_number % 10) + '0';
			write(1, &result, 5);
			if (!(left_number == 98 && right_number == 99))
				write(1, ", ", 2);
			++right_number;
		}
		++left_number;
	}
}
