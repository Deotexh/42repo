/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:10:37 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/09 19:41:48 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static unsigned int get_to_write_count(char *str, unsigned int limit)
{
	unsigned int str_len;

	str_len = ft_strlen(str);
	if (limit < str_len)
		return (limit);
	else
		return (str_len);
}

static void	vi_print_width_pad(unsigned int width_pad)
{
	if (width_pad == 0)
		return ;
	vi_print_alignment(width_pad, ' ');
}

void	vi_print_str(char *arg, t_format_specs infos)
{
	unsigned int	width_pad;
	unsigned int	to_write_count;

	if (infos.flags & FLAG_DOT)
		to_write_count = get_to_write_count(arg, infos.precision);
	else
		to_write_count = ft_strlen(arg);
	width_pad = infos.width - to_write_count;
	if (!(infos.flags & FLAG_DASH))
		vi_print_width_pad(width_pad);
	if (!(infos.precision == 0 && arg == 0))
		write(1, arg, to_write_count);
	if (infos.flags & FLAG_DASH)
		vi_print_width_pad(width_pad);
}
