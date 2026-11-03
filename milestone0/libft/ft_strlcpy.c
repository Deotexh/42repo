/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:52:21 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/03 17:35:38 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

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

// #include <stdio.h>
// #include <bsd/string.h>
// int main()
// {
// 	int size = 10;
// 	char dst[10] = "Ouais ";
// 	char *src = "nan";
// 	printf("%s\n", dst);
// 	printf("%s\n", src);
// 	printf("%zu\n", ft_strlcpy(dst, src, size));
// 	printf("%s\n", dst);
//
// 	char ddst[10] = "Ouais ";
// 	char *dsrc = "nan";
// 	printf("%s\n", ddst);
// 	printf("%s\n", dsrc);
// 	printf("%zu\n", strlcpy(ddst, dsrc, size));
// 	printf("%s\n", ddst);
// }
