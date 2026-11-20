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
	size_t longword;
	size_t	i;
	size_t align;
	size_t repeated_one;
	size_t repeated_nl;

	align = 0;
	while (align < result->offset % sizeof(size_t))
		if (result->str[align++] == '\n')
			return (1);
	repeated_one = 0x0101010101010101;
	repeated_nl = 0x0A0A0A0A0A0A0A0A;
	i = 0;
	while ((i + 1) * sizeof(size_t) < result->offset - align)
	{
		longword = ((size_t *)(result->str + align))[i] ^ repeated_nl;
		if ((((longword - repeated_one) & ~longword) & (repeated_one << 7)) != 0)
			break;
		i++;
	}
	align += i * sizeof(size_t);
	i = 0;
	while(i < sizeof(size_t) && align + i < result->offset)
		if ((result->str + align)[i++] == '\n')
			return (1);
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
