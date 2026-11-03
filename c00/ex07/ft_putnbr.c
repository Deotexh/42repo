/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:27:45 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/16 16:20:59 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ipow(int base, int exp)
{
	int	initial_base;

	initial_base = base;
	if (exp == 0)
		return (1);
	while (exp > 1)
	{
		base *= initial_base;
		--exp;
	}
	return (base);
}

void	ft_putnbr(int nb)
{
	int	nb_of_digits;
	int	buffer;
	int	i;

	nb_of_digits = 0;
	buffer = nb;
	i = 1;
	while (1)
	{
		++nb_of_digits;
		buffer /= 10;
		if (buffer == 0)
			break ;
	}
	while (i <= nb_of_digits)
	{
		buffer = (nb / ipow(10, nb_of_digits - i)) % 10;
		if (nb < 0 && i == 1)
			ft_putchar('-');
		if (nb < 0)
			ft_putchar(-buffer + '0');
		else
			ft_putchar(buffer + '0');
		++i;
	}
}
