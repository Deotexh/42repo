/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:50:46 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/12 16:06:08 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"

size_t	vi_print_char(unsigned char arg, t_format_specs infos)
{
	unsigned int	width_pad;

	if (infos.width > 1)
		width_pad = infos.width - 1;
	else
		width_pad = 0;
	if (!(infos.flags & FLAG_DASH))
		vi_print_alignment(width_pad, ' ');
	if (!(infos.precision == 0 && arg == 0))
		ft_putchar_fd(arg, 1);
	if (infos.flags & FLAG_DASH)
		vi_print_alignment(width_pad, ' ');
	return (width_pad + 1);
}
