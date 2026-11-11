/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:46:47 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 13:16:56 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

size_t	vi_print_ptr(void *arg, t_format_specs infos)
{
	size_t print_count;
	(void)infos;
	if (!arg)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	print_count = vi_recursive_hex_print((size_t)arg, 0);
	return (print_count + 2);
}
