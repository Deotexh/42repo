/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:47:54 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/07 13:42:28 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

static int	vi_is_fromset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	vi_handle_flags(const char *str, size_t i, unsigned char *flags)
{
	while (vi_is_fromset(str[i], "-0+ #"))
	{
		if (str[i] == '-')
			*flags |= FLAG_DASH;
		else if (str[i] == '+')
			*flags |= FLAG_PLUS;
		else if (str[i] == '#')
			*flags |= FLAG_HASHTAG;
		else if (str[i] == ' ')
			*flags |= FLAG_BLANK;
		else if (str[i] == '0')
			*flags |= FLAG_ZERO;
		i++;
	}
	return (i);
}

static size_t	vi_get_conversion_info(t_format_specs *infos, const char *str,
		size_t i)
{
	infos->flags = 0;
	infos->width = 0;
	infos->precision = 0;
	if (vi_is_fromset(str[i], "-0+ #"))
		i = vi_handle_flags(str, i, &(infos->flags));
	if (ft_isdigit(str[i]))
	{
		infos->width = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	if (str[i] == '.')
	{
		i += 1;
		infos->precision = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

size_t	vi_handle_formatspec(const char *str, size_t i, va_list *argptr)
{
	t_format_specs	infos;

	if (str[i] == '%')
	{
		ft_putchar_fd('%', 1);
		return (i + 1);
	}
	i = vi_get_conversion_info(&infos, str, i);
	if (!vi_is_fromset(str[i], "cspdiuxX"))
		return (-1);
	i = vi_print_arg(str[i], infos, argptr);
	return (i);
}
