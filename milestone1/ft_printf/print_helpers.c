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

size_t	vi_putnbr_fd_uint(long nbr, int fd)
{
	int	digit;
	size_t	print_count;

	print_count = 0;
	if (nbr / 10 != 0)
		print_count = vi_putnbr_fd_uint(nbr / 10, fd);
	digit = nbr % 10;
	ft_putchar_fd(digit + '0', fd);
	return (print_count + 1);
}

static char	vi_find_hex_char(size_t nbr, int is_useupcase)
{
	nbr %= 16;
	if (nbr <= 9)
		return (nbr + '0');
	else
		return (nbr - 10 + 'a' - (is_useupcase * 32));
}

size_t	vi_recursive_hex_print(size_t nbr, int is_useupcase)
{
	size_t print_count;

	print_count = 0;
	if (nbr / 16 != 0)
		print_count = vi_recursive_hex_print(nbr / 16, is_useupcase);
	ft_putchar_fd(vi_find_hex_char(nbr, is_useupcase), 1);
	return (print_count + 1);
}
