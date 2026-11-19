/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:39:57 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/18 18:50:15 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <unistd.h>

static void	vi_cancel_buf(t_fd_read_infos *buf)
{
	free(buf->str);
	buf->str = NULL;
	buf->fd = -1;
	buf->offset = 0;
	buf->size = 0;
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

static size_t	vi_read(int fd, t_fd_read_infos *buffer)
{
	ssize_t	read_bytes;

	if (buffer->offset + (size_t)BUFFER_SIZE + 1 > buffer->size)
	{
		buffer->str = vi_realloc(buffer->str, &(buffer->size), buffer->offset
				+ BUFFER_SIZE + 1);
		if (!buffer->str)
			return (-1);
	}
	read_bytes = read(fd, buffer->str + buffer->offset, BUFFER_SIZE);
	if (read_bytes == -1 || (!read_bytes && !buffer->offset))
		return (vi_cancel_buf(buffer), -1);
	else if (!read_bytes && buffer->offset)
		return (0);
	buffer->offset += read_bytes;
	return (1);
}

static size_t	vi_init(t_fd_infos_storer *arr, int fd)
{
	if (!arr->buffers)
	{
		arr->buffers = vi_realloc(arr->buffers, &(arr->size),
				sizeof(t_fd_read_infos));
		if (!arr->buffers)
			return (arr->error_occured = 1, 0);
	}
	return (vi_manage_buffers(arr, fd));
}

char	*get_next_line(int fd)
{
	static t_fd_infos_storer	buf_arr = {.buffers = NULL, .size = 0,
		.offset = 0, .error_occured = 0};
	ssize_t						buf_i;
	char						*result;
	int							read_code;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf_i = vi_init(&buf_arr, fd);
	if (buf_arr.error_occured || buf_i == -1)
		return (NULL);
	while (!vi_is_line(&(buf_arr.buffers[buf_i])))
	{
		read_code = vi_read(fd, &(buf_arr.buffers[buf_i]));
		if (read_code == -1)
			return (NULL);
		else if (read_code == 0)
			break ;
	}
	if (!vi_extract_excess(&(buf_arr.buffers[buf_i]), &result))
		return (free(result), NULL);
	return (result);
}
