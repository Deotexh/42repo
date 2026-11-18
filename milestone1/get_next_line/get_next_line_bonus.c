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

static void	*vi_realloc(void *ptr, size_t *old_size, size_t wish_size)
{
	char	*new;
	size_t	size;

	if (wish_size <= *old_size)
		return (ptr);
	size = vi_get_enough_size(wish_size);
	new = malloc(size);
	if (!new)
		return (free(ptr), NULL);
	if (ptr)
		vi_copy(new, ptr, *old_size);
	*old_size = size;
	return (free(ptr), new);
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
		buffer->str = vi_realloc(buffer, &(buffer->size), buffer->offset
				+ BUFFER_SIZE + 1);
		if (!buffer->str)
			return (-1);
	}
	read_bytes = read(fd, buffer->str + buffer->offset, BUFFER_SIZE);
	if (read_bytes == -1 || (!read_bytes && !buffer->offset))
		return (buffer->fd = -1, -1);
	else if (!read_bytes && buffer->offset)
		return (0);
	buffer->offset += read_bytes;
	return (1);
}

static void	vi_init(t_fd_infos_storer *arr, int fd)
{
	size_t	i;

	if (BUFFER_SIZE <= 0)
	{
		arr->error_occured = 1;
		return ;
	}
	arr->buffers = vi_realloc(arr->buffers, &(arr->size),
			sizeof(t_fd_read_infos));
	if (!arr->buffers)
		return ;
	i = 0;
	while (i < arr->size && arr->buffers[i].fd != -1)
		i++;
	if (i == arr->size)
		arr->buffers = vi_realloc(arr->buffers, &(arr->size), arr->size
				+ sizeof(t_fd_read_infos));
	else
		vi_manage_buffers(arr, i, BUF_SET, fd);
}

char	*get_next_line(int fd)
{
	static t_fd_infos_storer	buf_arr = {.buffers = NULL, .size = 0,
			.offset = 0, .error_occured = 0};
	ssize_t						buf_i;
	char						*result;
	int							read_code;

	vi_init(&buf_arr, fd);
	buf_i = vi_get_index_from_fd(&buf_arr, fd);
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
	{
		free(result);
		return (NULL);
	}
	return (result);
}
