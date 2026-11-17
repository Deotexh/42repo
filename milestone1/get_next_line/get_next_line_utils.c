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

void	vi_clear_buffer(char *buffer, size_t start, size_t end)
{
	size_t	i;

	i = start;
	while (i < end)
	{
		buffer[i] = '\0';
		i++;
	}
}

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
	while (i < result->size)
	{
		if (result->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
