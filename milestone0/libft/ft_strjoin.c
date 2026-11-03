/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:27:33 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/03 17:44:48 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

static int	vi_checkstr(const char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_cpy;
	size_t	dst_len;

	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
	size_cpy = size - dst_len - 1;
	if (size == 0 || vi_checkstr(dst, size) == 0)
		return (size + ft_strlen(src));
	i = 0;
	while (i < size_cpy)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (dst_len + ft_strlen(src));
}

size_t	ft_strlcpy( char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return 0;
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *new_str;
	int s1_len;
	int s2_len;

	if (!s1 || !s2)
		return ((void *)0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_str)
		return ((void *)0);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s1_len + s2_len + 1);
	return (new_str);
}

// #include <stdio.h>
// int main()
// {
// 	char *str1 = "Salut";
// 	char *str2 = "Mogno";
// 	char *ptr = ft_strjoin(str1, str2);
//
// 	printf("%x\n", *(ptr + 10));
//
// }
