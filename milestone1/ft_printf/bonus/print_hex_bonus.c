/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:50:59 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/12 16:12:25 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"

static unsigned int	vi_get_precision_padding(unsigned int precision_info,
		unsigned int digit_count)
{
	if (precision_info > digit_count)
		return (precision_info - digit_count);
	else
		return (0);
}

static unsigned int	vi_get_width_padding(unsigned int width_info,
		unsigned int digit_count, unsigned int precision_pad, int has_flag_hash)
{
	if (precision_pad == 0 && digit_count == 0)
		digit_count = 0;
	if (width_info > digit_count + precision_pad + (has_flag_hash * 2))
		return (width_info - (digit_count + precision_pad + (has_flag_hash
					* 2)));
	else
		return (0);
}

static size_t	vi_handle_hash(unsigned int arg, unsigned char flags,
		int has_flag_hash)
{
	if (flags & FLAG_HASH && !has_flag_hash && arg != 0)
	{
		ft_putstr_fd("0x", 1);
		return (2);
	}
	else if (flags & FLAG_HASH && has_flag_hash && arg != 0)
	{
		ft_putstr_fd("0X", 1);
		return (2);
	}
	return (0);
}

size_t	vi_print_hex(unsigned int arg, t_format_specs infos, char format_type)
{
	unsigned int	precision_pad;
	unsigned int	width_pad;
	unsigned int	digit_count;
	size_t			print_count;

	if (infos.flags & (FLAG_DOT | FLAG_DASH))
		infos.flags &= ~FLAG_ZERO;
	print_count = 0;
	digit_count = vi_count_digits_hex((size_t)arg);
	precision_pad = vi_get_precision_padding(infos.precision, digit_count);
	width_pad = vi_get_width_padding(infos.width, digit_count, precision_pad,
			(infos.flags & FLAG_HASH && arg != 0));
	if (!(infos.flags & (FLAG_DASH | FLAG_ZERO)))
		vi_print_alignment(width_pad, ' ');
	print_count += vi_handle_hash(arg, infos.flags, format_type == 'X');
	vi_print_alignment(precision_pad, '0');
	if (infos.flags & FLAG_ZERO)
		vi_print_alignment(width_pad, '0');
	if (!(infos.precision == 0 && arg == 0))
		print_count += vi_recursive_hex_print(arg, format_type == 'X');
	if (infos.flags & FLAG_DASH)
		vi_print_alignment(width_pad, ' ');
	return (print_count + width_pad + precision_pad);
}
