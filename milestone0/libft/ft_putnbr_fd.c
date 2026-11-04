/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:32:58 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/04 11:06:41 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static void	vi_print_digit(int nbr, int fd)
{
	int digit;

	if (nbr / 10 != 0)
		vi_print_digit(nbr / 10, fd);
	if (nbr < 0)
		digit = (nbr % 10) * -1;
	else
		digit = nbr % 10;
	ft_putchar_fd(digit + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	vi_print_digit(n, fd);
}
