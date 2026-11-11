/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:47:54 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/10 17:31:00 by vitruong         ###   ########.fr       */
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

size_t	vi_handle_formatspec(const char *str, size_t i, va_list *argptr,
		size_t *print_count)
{
	if (vi_is_fromset(str[i], "+ 0-#.%"))
	{
		ft_putchar_fd('%', 1);
		(*print_count)++;
		if (str[i] == '%')
			return (i + 1);
		else
			return (i);
	}
	*print_count = vi_print_arg(str[i], (t_format_specs){}, argptr);
	return (i + 1);
}
