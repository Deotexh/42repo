/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:16:11 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 13:13:46 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t	vi_print_uint(unsigned int arg, t_format_specs infos)
{
	size_t	print_count;

	(void)infos;
	print_count = vi_putnbr_fd_uint(arg, 1);
	return (print_count);
}
