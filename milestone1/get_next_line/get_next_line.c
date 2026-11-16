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

void	vi_clear_buffer(char *buffer, int buffer_size)
{
	int i;

	i = 0;
	while (i < buffer_size)
	{
		buffer[i] = '\0';
		i++;
	}
}

int	vi_extract_excess(t_fd_read_infos *excess, char *result, size_t result_size)
{
	size_t	i;
	size_t	extract_start;

	extract_start = 0;
	while (result[extract_start] != '\n')
		extract_start++;
	extract_start++;
	excess->str = malloc(result_size - extract_start);
	if (!excess->str)
		return (0);
	excess->size = (result_size - extract_start);
	i = 0;
	while (extract_start + i < result_size)
	{
		excess->str[i] = result[extract_start + i];
		result[extract_start + i] = '\0';
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_fd_read_infos	excess = {.str = NULL, .size = 0};
	char					buffer[BUFFER_SIZE + 1];
	char					*result;
	size_t					result_size;
	size_t					temp_read_bytes;

	vi_clear_buffer(buffer, BUFFER_SIZE + 1);
	temp_read_bytes = BUFFER_SIZE;
	result_size = vi_get_enough_size(excess.size);
	result = vi_realloc_str(excess.str, excess.size, result_size);
	if (!result)
		return (NULL);
	while (temp_read_bytes == BUFFER_SIZE && !vi_is_completeline(result,
			result_size))
	{
		temp_read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (!temp_read_bytes)
			return (NULL);
		if (vi_strlen(result) + (size_t)BUFFER_SIZE > result_size)
		{
			result_size = vi_get_enough_size(result_size + BUFFER_SIZE);
			result = vi_realloc_str(result, vi_strlen(result), result_size);
			if (!result)
				return (NULL);
		}
		vi_strlcat(result, buffer, result_size);
		vi_clear_buffer(buffer, BUFFER_SIZE + 1);
	}
	if (!vi_extract_excess(&excess, result, result_size))
		return (NULL);
	return (result);
}
