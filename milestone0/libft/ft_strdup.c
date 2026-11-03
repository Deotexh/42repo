/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:34:10 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/03 13:44:14 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (!s)
		return ((void *)0);
	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *str = "Bon\0Jour";
// 	char *ptr;
// 	ptr = ft_strdup(str);
// 	printf("%s\n", ptr);
// 	free(ptr);
//
// 	ptr = strdup(str);
// 	printf("%s\n", ptr);
// 	free(ptr);
// }
