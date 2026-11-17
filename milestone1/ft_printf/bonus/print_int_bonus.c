/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:50:46 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/12 16:18:11 by vitruong         ###   ########.fr       */
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

static unsigned int	vi_get_width_padding(unsigned int width_info, int nbr,
		unsigned int precision_pad, unsigned char flags)
{
	int				is_using_sign_pad;
	unsigned int	digit_count;

	digit_count = vi_count_digits_int(nbr);
	if (FLAG_DOT & flags && precision_pad == 0 && nbr == 0)
		digit_count = 0;
	is_using_sign_pad = ((nbr < 0) || (flags & (FLAG_PLUS + FLAG_BLANK)));
	if (width_info > digit_count + precision_pad + is_using_sign_pad)
		return (width_info - (digit_count + precision_pad + is_using_sign_pad));
	else
		return (0);
}

static void	vi_print_sign(int nbr, unsigned char flags)
{
	if ((flags & FLAG_PLUS) && nbr >= 0)
		ft_putchar_fd('+', 1);
	else if ((flags & FLAG_BLANK) && nbr >= 0)
		ft_putchar_fd(' ', 1);
	else if (nbr < 0)
		ft_putchar_fd('-', 1);
}

size_t	vi_print_int(int arg, t_format_specs infos)
{
	unsigned int	precision_pad;
	unsigned int	width_pad;
	unsigned int	digit_count;

	if (infos.flags & (FLAG_DOT | FLAG_DASH))
		infos.flags &= ~FLAG_ZERO;
	digit_count = vi_count_digits_int(arg);
	if (infos.precision == 0 && arg == 0)
		digit_count = 0;
	precision_pad = vi_get_precision_padding(infos.precision, digit_count);
	width_pad = vi_get_width_padding(infos.width, arg, precision_pad,
			infos.flags);
	if (!(infos.flags & (FLAG_DASH | FLAG_ZERO)))
		vi_print_alignment(width_pad, ' ');
	vi_print_sign(arg, infos.flags);
	vi_print_alignment(precision_pad, '0');
	if (infos.flags & FLAG_ZERO)
		vi_print_alignment(width_pad, '0');
	if (!(infos.precision == 0 && arg == 0))
		vi_putnbr_fd_uint(-(long)arg * (arg < 0) + (long)arg * (arg >= 0), 1);
	if (infos.flags & FLAG_DASH)
		vi_print_alignment(width_pad, ' ');
	return (width_pad + digit_count + (infos.flags & (FLAG_PLUS | FLAG_BLANK)
			|| arg < 0) + precision_pad);
}
