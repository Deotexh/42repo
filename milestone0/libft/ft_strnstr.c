/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:01:10 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/02 18:30:24 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	search_i;
	size_t	cmp_i;

	if (!big || !little)
		return ((void *)0);
	if (little[0] == '\0')
		return ((char *)big);
	search_i = 0;
	while (search_i < len && big[search_i] != '\0')
	{
		if (big[search_i] == little[0])
		{
			cmp_i = 0;
			while (little[cmp_i] != '\0')
			{
				if (cmp_i + search_i >= len)
					return ((void *)0);
				if (big[cmp_i + search_i] != little[cmp_i])
					break ;
				cmp_i++;
			}
			if (little[cmp_i] == '\0')
				return ((char *)(big + search_i));
		}
		search_i++;
	}
	return ((void *)0);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int main()
// {
// 	char *s1 = "Bonjour";
// 	char *s2 = (void *)0;
// 	char len = 16;
//
// 	printf("%p\n", ft_strnstr(s1, s2, len));
// 	printf("%p\n", strnstr(s1, s2, len));
// }
