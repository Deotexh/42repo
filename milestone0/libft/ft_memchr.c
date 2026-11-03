/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:42:06 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/02 17:50:48 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return ((void *)0);
	i = 0;
	while (i < n)
	{
		if (*((char *)s + i) == c)
			return ((void *)s + i);
		i++;
	}
	return ((void *)0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *str = "Bonjour";
// 	char needle = 'B';
//
// 	printf("%p\n", ft_memchr(str, needle, 8));
// 	printf("%p\n", memchr(str, needle, 8));
// }
