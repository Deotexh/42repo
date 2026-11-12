/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:50:59 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/12 16:02:53 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

size_t	vi_print_hex(unsigned int arg, t_format_specs infos, char format_type)
{
	size_t	print_count;

	(void)infos;
	print_count = vi_recursive_hex_print((size_t)arg, (format_type == 'X'));
	return (print_count);
}
