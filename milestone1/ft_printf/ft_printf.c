/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:43:01 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/06 19:50:08 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	size_t	print_i;

	va_start(argptr, str);
	print_i = 0;
	while (str[print_i] != '\0')
	{
		if (str[print_i] == '%')
		{
			print_i = vi_handle_formatspec(str, print_i + 1, &argptr);
			continue ;
		}
		ft_putchar_fd(str[print_i], 1);
		print_i++;
	}
	va_end(argptr);
	return(print_i);
}

size_t	vi_print_arg(char conversion_type, t_format_specs infos,
	va_list *argptr)
{
	if (conversion_type == 'd' || conversion_type == 'i')
		vi_print_int(va_arg(*argptr, int));
	else if (conversion_type == 'c') { }
		ft_putchar_fd(va_arg(*argptr, char), 1);
	else if (conversion_type == 's') { }
		vi_print_str(va_arg(*argptr, char *));
	else if (conversion_type == 'p') { }
		vi_print_ptr(va_arg(*argptr, void *));
	else if (conversion_type == 'u') { }
		vi_print_uint(va_arg(*argptr, unsigned int));
	else if (conversion_type == 'x' || conversion_type == 'X') { }
		vi_print_hex(va_arg(*argptr, unsigned int));
}

