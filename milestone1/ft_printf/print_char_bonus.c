/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:50:46 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 13:19:18 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static void	vi_print_width_pad(unsigned int width_pad)
{
	if (width_pad == 0)
		return ;
	vi_print_alignment(width_pad, ' ');
}

size_t	vi_print_char(unsigned char arg, t_format_specs infos)
{
	unsigned int	width_pad;

	if (infos.width > 1)
		width_pad = infos.width - 1;
	else
		width_pad = 0;
	if (!(infos.flags & FLAG_DASH))
		vi_print_width_pad(width_pad);
	if (!(infos.precision == 0 && arg == 0))
		ft_putchar_fd(arg, 1);
	if (infos.flags & FLAG_DASH)
		vi_print_width_pad(width_pad);
	return (width_pad + 1);
}
