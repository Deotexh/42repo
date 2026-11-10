/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:07:06 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/09 18:26:26 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"

void	vi_print_alignment(int count, char c)
{
	int i;
	
	i = 0;
	while(i < count)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}

unsigned int	vi_get_precision_padding(unsigned int precision_info,
		unsigned int digit_count)
{
	if (precision_info < 0)
		return (0);
	else if (precision_info > digit_count)
		return (precision_info - digit_count);
	else
		return (0);
}

unsigned int	vi_get_width_padding(unsigned int width_info, int nbr,
		unsigned int precision_pad, unsigned char flags)
{
	int				is_using_sign_pad;
	unsigned int	digit_count;

	digit_count = vi_count_digits_int(nbr);
	if (precision_pad == 0 && nbr == 0)
		digit_count = 0;
	is_using_sign_pad = ((nbr < 0) || (flags & FLAG_PLUS + FLAG_BLANK));
	if (width_info > digit_count + precision_pad + is_using_sign_pad)
		return (width_info - (digit_count + precision_pad + is_using_sign_pad));
	else
		return (0);
}
