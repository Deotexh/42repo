/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:05:59 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 13:19:36 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stddef.h>

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

static char	find_hex_char(size_t nbr, int is_useupcase)
{
	nbr %= 16;
	if (nbr <= 9)
		return (nbr + '0');
	else
		return (nbr - 10 + 'a' - (is_useupcase * 32));
}

void	vi_recursive_hex_print(size_t nbr, int is_useupcase)
{
	if (nbr / 16 != 0)
		vi_recursive_hex_print(nbr / 16, is_useupcase);
	ft_putchar_fd(find_hex_char(nbr, is_useupcase), 1);
}
