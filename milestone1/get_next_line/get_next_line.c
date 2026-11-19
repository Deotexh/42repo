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

static char	*vi_realloc(t_fd_read_infos *info, size_t wish_size)
{
	char	*new;
	size_t	size;

	if (wish_size <= info->size)
		return (info->str);
	size = vi_get_enough_size(wish_size);
	new = malloc(size);
	if (!new)
		return (free(info->str), NULL);
	if (info->str)
		vi_copy(new, info->str, info->offset);
	info->size = size;
	return (free(info->str), new);
}

static int	vi_extract_excess(t_fd_read_infos *buffer, char **result)
{
	size_t	result_end;

	result_end = 0;
	while (buffer->str[result_end] != '\n' && result_end + 1 < buffer->offset)
		result_end++;
	*result = buffer->str;
	if (result_end + 1 >= buffer->offset)
	{
		(*result)[result_end + 1] = '\0';
		buffer->str = NULL;
		buffer->size = 0;
		buffer->offset = 0;
		return (1);
	}
	buffer->size = (buffer->offset - (result_end));
	buffer->str = malloc(buffer->size);
	if (!buffer->str)
		return (0);
	vi_copy(buffer->str, (*result) + result_end + 1, buffer->size - 1);
	(*result)[result_end + 1] = '\0';
	buffer->offset = buffer->size - 1;
	return (1);
}

static void	vi_init(t_fd_read_infos *buffer, char **result)
{
	if (BUFFER_SIZE <= 0)
	{
		buffer->str = NULL;
		return ;
	}
	if (!buffer->str)
	{
		buffer->size = 0;
		buffer->offset = 0;
	}
	buffer->str = vi_realloc(buffer, buffer->offset + 1);
	*result = NULL;
}

static size_t	vi_read(int fd, t_fd_read_infos *buffer)
{
	ssize_t	read_bytes;

	if (buffer->offset + (size_t)BUFFER_SIZE + 1 > buffer->size)
	{
		buffer->str = vi_realloc(buffer, buffer->offset + BUFFER_SIZE + 1);
		if (!buffer->str)
			return (-1);
	}
	read_bytes = read(fd, buffer->str + buffer->offset, BUFFER_SIZE);
	if (read_bytes == -1 || (!read_bytes && !buffer->offset))
		return (free(buffer->str), buffer->str = NULL, -1);
	else if (!read_bytes && buffer->offset)
		return (0);
	buffer->offset += read_bytes;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_fd_read_infos	buffer = {.str = NULL, .size = 0, .offset = 0};
	char					*result;
	int						read_code;

	vi_init(&buffer, &result);
	if (!buffer.str)
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
	{
		free(result);
		return (NULL);
	}
	return (result);
}
