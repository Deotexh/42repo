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

static char	*vi_realloc_str(char *str, size_t old_size, size_t size)
{
	char	*new;
	size_t	i;

	if (size <= old_size || size == 0)
		return (str);
	new = malloc(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < old_size && str)
	{
		new[i] = str[i];
		i++;
	}
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	free(str);
	return (new);
}

static int	vi_extract_excess(t_fd_read_infos *excess, t_fd_read_infos *result)
{
	ssize_t	i;
	size_t	extract_start;

	extract_start = 0;
	while (result->str[extract_start] != '\n' && extract_start < result->len)
		extract_start++;
	extract_start++;
	if (extract_start >= result->len)
	{
		excess->str = NULL;
		return (1);
	}
	excess->size = (result->len - extract_start + 1);
	excess->str = malloc(result->size);
	if (!excess->str)
		return (0);
	i = -1;
	while (extract_start + ++i < result->len)
	{
		excess->str[i] = result->str[extract_start + i];
		result->str[extract_start + i] = '\0';
	}
	excess->str[i] = '\0';
	excess->len = i;
	return (1);
}

static void	vi_init(char **buffer, size_t *temp_read_bytes,
		t_fd_read_infos *result, t_fd_read_infos *excess)
{
	*buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	vi_clear_buffer(*buffer, 0);
	*temp_read_bytes = BUFFER_SIZE;
	result->size = vi_get_enough_size(excess->size);
	result->str = vi_realloc_str(excess->str, excess->size, result->size);
	if (!excess->str)
		result->len = 0;
	else
		result->len = excess->len;
}

static size_t	vi_read(int fd, char *buffer)
{
	size_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes != BUFFER_SIZE)
		vi_clear_buffer(buffer, read_bytes);
	return (read_bytes);
}

char	*get_next_line(int fd)
{
	static t_fd_read_infos	excess = {.str = NULL, .size = 0, .len = 0};
	t_fd_read_infos			result;
	char					*buffer;
	size_t					read_bytes;

	vi_init(&buffer, &read_bytes, &result, &excess);
	if (!result.str || !buffer)
		return (NULL);
	while (read_bytes == BUFFER_SIZE && !vi_is_line(&result))
	{
		read_bytes = vi_read(fd, buffer);
		if (!read_bytes && !result.len)
			return (NULL);
		if (result.len + (size_t)BUFFER_SIZE + 1 > result.size)
		{
			result.size = vi_get_enough_size(result.size + BUFFER_SIZE);
			result.str = vi_realloc_str(result.str, result.len, result.size);
			if (!result.str)
				return (NULL);
		}
		vi_append_buffer(&result, buffer);
	}
	if (!vi_extract_excess(&excess, &result))
		return (NULL);
	return (result.str);
}
