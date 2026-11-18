/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:33:45 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/16 14:45:55 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	vi_get_enough_size(size_t old_size)
{
	size_t	new_size;

	new_size = 8;
	while (new_size < old_size)
		new_size *= 2;
	return (new_size);
}

char	vi_is_line(t_fd_read_infos *result)
{
	size_t	i;

	i = 0;
	while (i < result->offset)
	{
		if (result->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	vi_copy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i + sizeof(size_t) < len)
	{
		*(size_t *)(dst + i) = *(size_t *)(src + i);
		i += sizeof(size_t);
	}
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
