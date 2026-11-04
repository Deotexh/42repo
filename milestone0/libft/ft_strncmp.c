/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:28:49 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/02 18:06:30 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	unsigned char s1_c;
	unsigned char s2_c;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		s1_c = s1[i];
		s2_c = s2[i];
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return (s1_c - s2_c);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *s1 = "\0Bonjour";
// 	char *s2 = "\0Bonj";
// 	int bytes = 90;
//
// 	printf("%d\n", ft_strncmp(s1, s2, bytes));
// 	printf("%d\n", strncmp(s1, s2, bytes));
// }
