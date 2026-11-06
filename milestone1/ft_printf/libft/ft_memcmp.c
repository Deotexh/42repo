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
	size_t			i;
	unsigned char	s1_c;
	unsigned char	s2_c;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		s1_c = ((unsigned char *)s1)[i];
		s2_c = ((unsigned char *)s2)[i];
		if (s1_c != s2_c)
			return (s1_c - s2_c);
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
