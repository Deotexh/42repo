/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:28:49 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/02 18:04:45 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if (*((char *)s1 + i) != *((char *)s2 + i))
			return (*((char *)s1 + i) - *((char *)s2 + i));
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *s1 = "Bonjour";
// 	char *s2 = "Aonjxur";
// 	int bytes = 4;
//
// 	printf("%d\n", ft_memcmp(s1, s2, bytes));
// 	printf("%d\n", memcmp(s1, s2, bytes));
// }
