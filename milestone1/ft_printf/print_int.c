/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:50:46 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 13:17:11 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

size_t	vi_print_int(int arg, t_format_specs infos)
{
	size_t print_count;

	(void)infos;
	if (arg < 0)
		ft_putchar_fd('-', 1);
	print_count = vi_putnbr_fd_uint(-arg * (arg < 0) + arg * (arg >= 0), 1);
	return (print_count);
}
