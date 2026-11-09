/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:43:01 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/09 19:50:55 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

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
	return (print_i);
}

void	vi_print_arg(char format_type, t_format_specs infos, va_list *argptr)
{
	if (format_type == 'd' || format_type == 'i')
		vi_print_int(va_arg(*argptr, int), infos);
	else if (format_type == 'u')
		vi_print_uint(va_arg(*argptr, unsigned int), infos);
	else if (format_type == 'c')
		vi_print_char((unsigned char)va_arg(*argptr, int), infos);
	else if (format_type == 's')
		vi_print_str(va_arg(*argptr, char *), infos);
	else if (format_type == 'x' || format_type == 'X')
		vi_print_hex(va_arg(*argptr, unsigned int), infos, format_type);
	// else if (format_type == 'p')
	// 	vi_print_ptr(va_arg(*argptr, void *), infos);
}
