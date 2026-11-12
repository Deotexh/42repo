/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:46:47 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/12 16:20:26 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"

static unsigned int	vi_get_precision_padding(unsigned int precision_info,
		unsigned int digit_count)
{
	if (digit_count == 0)
		return (0);
	if (precision_info > digit_count)
		return (precision_info - digit_count);
	return (0);
}

static unsigned int	vi_get_width_padding(unsigned int width_info,
		unsigned int char_count, unsigned int precision_pad)
{
	if (precision_pad == 0 && char_count == 0)
	{
		if (width_info > 5)
			return (width_info - 5);
		else
			return (0);
	}
	if (width_info > char_count + precision_pad + 2)
		return (width_info - (char_count + precision_pad + 2));
	return (0);
}

static unsigned int	vi_get_char_count(size_t arg)
{
	if (arg == 0)
		return (0);
	return (vi_count_digits_hex(arg));
}

size_t	vi_print_ptr(void *arg, t_format_specs infos)
{
	unsigned int	precision_pad;
	unsigned int	width_pad;
	unsigned int	char_count;

	char_count = vi_get_char_count((size_t)arg);
	precision_pad = vi_get_precision_padding(infos.precision, char_count);
	width_pad = vi_get_width_padding(infos.width, char_count, precision_pad);
	if (!(infos.flags & FLAG_DASH))
		vi_print_alignment(width_pad, ' ');
	if (arg)
	{
		ft_putstr_fd("0x", 1);
		vi_print_alignment(precision_pad, '0');
		vi_recursive_hex_print((size_t)arg, 0);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		char_count = 5;
	}
	if (infos.flags & FLAG_DASH)
		vi_print_alignment(width_pad, ' ');
	return (char_count + precision_pad + width_pad + (!!arg) * 2);
}
