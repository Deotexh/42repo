/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:47:54 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 13:19:02 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"

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
			*flags |= FLAG_HASH;
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
	infos->precision = 1;
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
		infos->flags |= FLAG_DOT;
		i += 1;
		infos->precision = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

int	verify_format_syntax(const char *str, size_t i)
{
	while (vi_is_fromset(str[i], "-0+ #"))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		i += 1;
		while (ft_isdigit(str[i]))
			i++;
	}
	if (vi_is_fromset(str[i], "cspdiuxX"))
		return (1);
	return (0);
}

size_t	vi_handle_formatspec(const char *str, size_t i, va_list *argptr,
		size_t *print_count)
{
	t_format_specs	infos;

	if (str[i] == '%')
	{
		ft_putchar_fd('%', 1);
		(*print_count)++;
		return (i + 1);
	}
	if (!verify_format_syntax(str, i))
	{
		ft_putchar_fd('%', 1);
		(*print_count)++;
		return (i);
	}
	i = vi_get_conversion_info(&infos, str, i);
	*print_count = vi_print_arg(str[i], infos, argptr);
	return (i + 1);
}
