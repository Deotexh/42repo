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
	ssize_t	i;
	size_t	print_count;

	if (!str || write(1, "", 0) == -1)
		return (-1);
	va_start(argptr, str);
	i = 0;
	print_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i = vi_handle_formatspec(str, i + 1, &argptr, &print_count);
			if (i == -1)
				return (-1);
			continue ;
		}
		ft_putchar_fd(str[i], 1);
		i++;
		print_count++;
	}
	va_end(argptr);
	return (print_count);
}

size_t	vi_print_arg(char format_type, t_format_specs infos, va_list *argptr)
{
	size_t	print_count;

	print_count = 0;
	if (format_type == 'd' || format_type == 'i')
		print_count = vi_print_int(va_arg(*argptr, int), infos);
	else if (format_type == 'u')
		print_count = vi_print_uint(va_arg(*argptr, unsigned int), infos);
	else if (format_type == 'c')
		print_count = vi_print_char((unsigned char)va_arg(*argptr, int), infos);
	else if (format_type == 's')
		print_count = vi_print_str(va_arg(*argptr, char *), infos);
	else if (format_type == 'x' || format_type == 'X')
		print_count = vi_print_hex(va_arg(*argptr, unsigned int), infos,
				format_type);
	else if (format_type == 'p')
		print_count = vi_print_ptr(va_arg(*argptr, void *), infos);
	return (print_count);
}
