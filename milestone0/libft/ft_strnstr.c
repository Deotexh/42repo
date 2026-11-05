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

static int	vi_cmp_str(const char *big, const char *little, size_t start_i,
	size_t len)
{
	size_t	cmp_i;

	cmp_i = 0;
	while (little[cmp_i] != '\0')
	{
		if (cmp_i + start_i >= len)
			return (-1);
		if (big[cmp_i + start_i] != little[cmp_i])
			return (0);
		cmp_i++;
	}
	if (little[cmp_i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	search_i;
	int		cmp_res;

	if (!big || !little)
		return ((void *)0);
	if (little[0] == '\0')
		return ((char *)big);
	search_i = 0;
	while (search_i < len && big[search_i] != '\0')
	{
		if (big[search_i] == little[0])
		{
			cmp_res = vi_cmp_str(big, little, search_i, len);
			if (cmp_res == -1)
				return ((void *)0);
			else if (cmp_res == 1)
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
