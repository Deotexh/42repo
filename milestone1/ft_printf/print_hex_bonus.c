/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:50:59 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/10 15:53:04 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static unsigned int	vi_get_precision_padding(unsigned int precision_info,
		unsigned int digit_count)
{
	if (precision_info < 0)
		return (0);
	else if (precision_info > digit_count)
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

static void	vi_print_width_pad(unsigned int width_pad, unsigned char flags,
		unsigned int precision_pad)
{
	if (width_pad == 0)
		return ;
	if ((flags & FLAG_ZERO) && precision_pad == 0)
		vi_print_alignment(width_pad, '0');
	else
		vi_print_alignment(width_pad, ' ');
}

static void	vi_recursive_hex_print(size_t nbr, int is_useupcase)
{
	if (nbr / 16 != 0)
		vi_recursive_hex_print(nbr / 16, is_useupcase);
	ft_putchar_fd(find_hex_char(nbr, is_useupcase), 1);
}

void	vi_print_hex(unsigned int arg, t_format_specs infos, char format_type)
{
	unsigned int	precision_pad;
	unsigned int	width_pad;
	unsigned int	digit_count;

	digit_count = vi_count_digits_hex((size_t)arg);
	precision_pad = vi_get_precision_padding(infos.precision, digit_count);
	width_pad = vi_get_width_padding(infos.width, digit_count, precision_pad,
			infos.flags & FLAG_HASH);
	if (!(infos.flags & FLAG_DASH) && !(infos.flags & FLAG_ZERO))
		vi_print_width_pad(width_pad, infos.flags, precision_pad);
	if (infos.flags & FLAG_HASH && !(format_type == 'X') && arg != 0)
		ft_putstr_fd("0x", 1);
	else if (infos.flags & FLAG_HASH && (format_type == 'X') && arg != 0)
		ft_putstr_fd("0X", 1);
	vi_print_alignment(precision_pad, '0');
	if (!(infos.flags & FLAG_DASH) && infos.flags & FLAG_ZERO)
		vi_print_width_pad(width_pad, infos.flags, precision_pad);
	if (!(infos.precision == 0 && arg == 0))
		vi_recursive_hex_print((size_t)arg, (format_type == 'X'));
	if (infos.flags & FLAG_DASH)
		vi_print_width_pad(width_pad, infos.flags, precision_pad);
}
