/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:52:21 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/03 15:13:06 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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

#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char dst[10] = "Ouais ";
	char *src = "nan";
	printf("%s\n", dst);
	printf("%s\n", src);
	printf("%zu\n", ft_strlcat(dst, src, 16));
	printf("%s\n", dst);

	char ddst[10] = "Ouais ";
	char *dsrc = "nan";
	printf("%s\n", ddst);
	printf("%s\n", dsrc);
	printf("%zu\n", strlcat(ddst, dsrc, 16));
	printf("%s\n", ddst);
}
