/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:39:57 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/16 14:46:26 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>

static void	vi_realloc(t_fd_read_infos *info, size_t wish_size)
{
	char	*new;
	size_t	size;
	size_t	i;

	size = vi_get_enough_size(wish_size);
	new = malloc(size);
	if (!new)
	{
		free(info->str);
		info->str = NULL;
		return ;
	}
	i = 0;
	while (i < info->offset && info->str)
	{
		new[i] = info->str[i];
		i++;
	}
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	free(info->str);
	info->str = new;
	info->size = size;
	return ;
}

static int	vi_extract_excess(t_fd_read_infos *buffer, char **result)
{
	size_t	i;
	size_t	extract_start;

	extract_start = 0;
	while (buffer->str[extract_start] != '\n' && extract_start < buffer->offset)
		extract_start++;
	*result = buffer->str;
	if (extract_start + 1 > buffer->offset)
	{
		buffer->str = NULL;
		return (1);
	}
	buffer->size = (buffer->offset - extract_start - 1);
	buffer->str = malloc(buffer->size);
	if (!buffer->str)
		return (0);
	i = 0;
	while (i < buffer->size + 1)
	{
		buffer->str[i] = (*result)[extract_start + 1 + i];
		(*result)[extract_start + 1 + i] = '\0';
		i++;
	}
	buffer->offset = i;
	return (1);
}

static void	vi_init(t_fd_read_infos *buffer, char **result)
{
	vi_realloc(buffer, buffer->size);
	*result = NULL;
}

static size_t	vi_read(int fd, t_fd_read_infos *buffer)
{
	size_t	read_bytes;

	if (buffer->offset + (size_t)BUFFER_SIZE + 1 > buffer->size)
	{
		vi_realloc(buffer, buffer->offset + BUFFER_SIZE);
		if (!buffer->str)
			return (-1);
	}
	read_bytes = read(fd, buffer->str + buffer->offset, BUFFER_SIZE);
	if (!read_bytes)
	{
		return (0);
	}
	buffer->offset += read_bytes;
	if (read_bytes != BUFFER_SIZE)
		vi_clear_buffer(buffer->str, buffer->offset, buffer->size);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_fd_read_infos	buffer = {.str = NULL, .size = 0, .offset = 0,
			.is_active = 1};
	int						read_code;
	char					*result;

	vi_init(&buffer, &result);
	if (!buffer.is_active)
		return (NULL);
	while (!vi_is_line(&buffer))
	{
		read_code = vi_read(fd, &buffer);
		if (read_code == -1)
			return (NULL);
		else if (read_code == 0)
			break ;
	}
	if (!vi_extract_excess(&buffer, &result))
		return (NULL);
	return (result);
}
