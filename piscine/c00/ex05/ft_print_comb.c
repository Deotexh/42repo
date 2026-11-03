/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:48:42 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/17 12:01:28 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int		digits;

	digits = 012;
	while ((digits / 100) <= 7)
	{
		digits = (digits / 100 * 100) + (digits / 100 * 10 + 10);
		while ((digits / 10) % 10 <= 8)
		{
			digits += digits / 10 % 10 + 1;
			while (digits % 10 != 0)
			{
				ft_putchar(digits / 100 + '0');
				ft_putchar(digits / 10 % 10 + '0');
				ft_putchar(digits % 10 + '0');
				if (digits < 789)
					write(1, ", ", 2);
				++digits;
			}
		}
		digits += 100;
	}
}
