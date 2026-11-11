/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:50:59 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 14:02:55 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

void	vi_print_hex(unsigned int arg, t_format_specs infos, char format_type)
{
	vi_recursive_hex_print((size_t)arg, (format_type == 'X'));
}
