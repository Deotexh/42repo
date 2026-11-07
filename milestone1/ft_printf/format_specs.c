/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:47:54 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/06 19:49:38 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static size_t	vi_handle_flags(char *str, size_t i, unsigned char *flags)
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

static size_t	vi_get_conversion_info(t_format_specs *infos, size_t i)
{
	info->flags = 0;
	info->width = 0;
	info->precision = 0;

	if (vi_is_fromset(str[i], "-0+ #"))
		i = vi_handle_flags(str, i, &(info->flags));
	if (ft_isdigit(str[i]))
	{
		info->width = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	if (str[i] == '.')
	{
		i += 1;
		info->precision = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

size_t	vi_handle_formatspec(char *str, size_t i, va_list *argptr)
{
	t_format_specs	infos;

	if (str[i] == '%')
	{
		ft_putchar_fd('%', 1);
		return (i + 1);
	}
	i = vi_get_conversion_info(&infos, i);
	if (!vi_is_fromset(str[i], "cspdiuxX"))
		return (-1);
	i = vi_print_arg(str[i], infos, argptr);
	return(i);
}
