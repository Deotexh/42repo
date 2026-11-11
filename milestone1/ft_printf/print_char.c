/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:50:46 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 13:19:27 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

size_t	vi_print_char(unsigned char arg, t_format_specs infos)
{
	(void)infos;
	ft_putchar_fd(arg, 1);
	return (1);
}
