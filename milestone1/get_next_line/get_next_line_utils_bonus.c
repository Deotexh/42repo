/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:33:45 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/18 18:44:02 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

ssize_t	vi_get_index_from_fd(t_fd_infos_storer *arr, int fd)
{
	size_t i;

	i = 0;
	while (i < arr->size)
	{
		if (arr->buffers[i].fd == fd)
			return (i);
		i++;
	}
	return (-1);
}

void	vi_manage_buffers(t_fd_infos_storer *arr, size_t index,
		unsigned char op_code, int fd)
{
	if (op_code == BUF_SET)
	{
		free(arr->buffers[index].str);
		arr->buffers[index] = (t_fd_read_infos){NULL, 0, 0, fd};
	}
}
