/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:01:10 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/02 17:41:44 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	c = (unsigned char)c % 256;
	if (!s)
		return ((void *)0);
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return ((void *)0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *str = "Bonjour";
// 	char needle = 'c';
//
// 	printf("%p\n", ft_strchr(str, needle));
// 	printf("%p\n", strrchr(str, needle));
// }
