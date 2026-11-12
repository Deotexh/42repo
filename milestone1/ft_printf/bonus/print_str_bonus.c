/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:10:37 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/12 16:21:53 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"

static unsigned int	get_to_write_count(char *str, unsigned int limit)
{
	unsigned int	str_len;

	str_len = ft_strlen(str);
	if (limit < str_len)
		return (limit);
	else
		return (str_len);
}

size_t	vi_print_str(char *arg, t_format_specs infos)
{
	unsigned int	width_pad;
	unsigned int	to_write_count;

	if (!arg)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	if (infos.flags & FLAG_DOT)
		to_write_count = get_to_write_count(arg, infos.precision);
	else
		to_write_count = ft_strlen(arg);
	width_pad = 0;
	if (infos.width > to_write_count)
		width_pad = infos.width - to_write_count;
	if (!(infos.flags & FLAG_DASH))
		vi_print_alignment(width_pad, ' ');
	if (!(infos.precision == 0 && arg == 0))
		write(1, arg, to_write_count);
	if (infos.flags & FLAG_DASH)
		vi_print_alignment(width_pad, ' ');
	return (width_pad + to_write_count);
}
