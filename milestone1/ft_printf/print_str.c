/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:10:37 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 13:12:25 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

size_t	vi_print_str(char *arg, t_format_specs infos)
{
	(void)infos;
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg));
}
