/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:10:35 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/10 17:24:54 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stddef.h>

unsigned int	vi_count_digits_hex(size_t n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

unsigned int	vi_count_digits_int(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

unsigned int	vi_count_digits_uint(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	vi_print_digit_uint(long nbr, int fd)
{
	int	digit;

	if (nbr / 10 != 0)
		vi_print_digit_uint(nbr / 10, fd);
	digit = nbr % 10;
	ft_putchar_fd(digit + '0', fd);
}

void	vi_putnbr_fd_uint(long n, int fd)
{
	vi_print_digit_uint(n, fd);
}

char	find_hex_char(size_t nbr, int is_useupcase)
{
	nbr %= 16;
	if (nbr <= 9)
		return (nbr + '0');
	else
		return (nbr - 10 + 'a' - (is_useupcase * 32));
}
	
