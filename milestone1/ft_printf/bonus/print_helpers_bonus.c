/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:07:06 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/11 13:19:42 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../ft_printf.h"

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
