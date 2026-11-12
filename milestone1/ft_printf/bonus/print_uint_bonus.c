/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:16:11 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/12 16:02:27 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static unsigned int	vi_get_precision_padding(unsigned int precision_info,
		unsigned int digit_count)
{
	if (precision_info > digit_count)
		return (precision_info - digit_count);
	return (0);
}

static unsigned int	vi_get_width_padding(unsigned int width_info,
		unsigned int nbr, unsigned int precision_pad)
{
	unsigned int	digit_count;

	if (precision_pad == 0 && nbr == 0)
		digit_count = 0;
	else
		digit_count = vi_count_digits_uint(nbr);
	if (width_info > digit_count + precision_pad)
		return (width_info - (digit_count + precision_pad));
	return (0);
}

static void	vi_print_width_pad(unsigned int width_pad, unsigned char flags,
		unsigned int precision_pad)
{
	if ((flags & FLAG_ZERO) && precision_pad == 0)
		vi_print_alignment(width_pad, '0');
	else
		vi_print_alignment(width_pad, ' ');
}

size_t	vi_print_uint(unsigned int arg, t_format_specs infos)
{
	unsigned int	precision_pad;
	unsigned int	width_pad;
	unsigned int	digit_count;

	digit_count = vi_count_digits_uint(arg);
	precision_pad = vi_get_precision_padding(infos.precision, digit_count);
	width_pad = vi_get_width_padding(infos.width, arg, precision_pad);
	if (!(infos.flags & FLAG_DASH))
		vi_print_width_pad(width_pad, infos.flags, precision_pad);
	vi_print_alignment(precision_pad, '0');
	if (!(infos.precision == 0 && arg == 0))
		vi_putnbr_fd_uint(arg, 1);
	if (infos.flags & FLAG_DASH)
		vi_print_width_pad(width_pad, infos.flags, precision_pad);
	return (digit_count * !(infos.precision == 0 && arg == 0) + width_pad
		+ precision_pad);
}
