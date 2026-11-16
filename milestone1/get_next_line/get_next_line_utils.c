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

char	*vi_realloc_str(char *str, size_t old_size, size_t size)
{
	char	*new;
	size_t	i;

	if (size <= old_size || size == 0)
		return (str);
	new = malloc(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < old_size)
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

size_t vi_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	vi_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_cpy;
	size_t	dst_len;

	if (!dst || !src)
		return ;
	dst_len = vi_strlen(dst);
	size_cpy = size - dst_len - 1;
	i = 0;
	while (i < size_cpy)
	{
		if (src[i] == '\0')
			break ;
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
}

size_t	vi_get_enough_size(size_t old_size)
{
	size_t	new_size;

	new_size = 8;
	while (new_size < old_size)
		new_size *= 2;
	return (new_size);
}

char	vi_is_completeline(char *result, size_t result_size)
{
	size_t	i;

	i = 0;
	while (i < result_size)
	{
		if (result[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
