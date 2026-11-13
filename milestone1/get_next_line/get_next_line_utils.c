/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:33:45 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/13 10:35:54 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char *vi_realloc_str(char *str, size_t old_size, size_t size)
{
	char *new;
	size_t	i;

	if (size <= old_size || size == 0)
		return (str);
	new = malloc(size);
	if (!new)
		return (NULL);
	if (!str)
		return (new);
	i = 0;
	while (i < old_size)
	{
		new[i] = str[i];
		i++;
	}
	new[size - 1] = '\0';
	return (new);
}

void	vi_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_cpy;
	size_t	dst_len;

	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
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
	return (dst_len + ft_strlen(src));
}

char	vi_is_linecomplete(char *result, size_t result_size)
{
	size_t i;

	i = 0;
	while (i < result_size)
	{
		if (result[i] == '\n')
			return (1);
	}
	return (0);
}

char *vi_extract_after_newline(char *result, size_t result_size)
{
	char *leftover;
	size_t i;
	size_t extract_start;

	extract_start = 0;
	while (extract_start != '\n')
		extract_start++;
	extract_start++;
	leftover = malloc(result_size - extract_start);
	if (!leftover)
		return (NULL);
	i = 0;
	while (i < result_size - extract_start)
	{
		leftover[i] = result[i + extract_start]
		result[i + extract_start] = '\0';
		i++;
	}
	return (leftover);
}

size_t	vi_get_enough_size(size_t old_size)
{
	size_t new_size;

	new_size = 8;
	while (new_size < old_size)
		new_size *= 2;
	return (new_size);
}
