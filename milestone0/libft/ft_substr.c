/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:12:33 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/03 17:26:49 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <limits.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	size_t end;
	size_t i;
	size_t str_size;

	if (!s)
		return ((void *)0);
	end = 0;
	while (s[end] != '\0')
		end++;
	if (end < len)
		str_size = end + 1;
	else
		str_size = len + 1;
	sub = malloc(str_size);
	if (!sub)
		return ((void *)0);
	i = 0;
	if (start < end)
	{
		while (i < len && s[start + i] != '\0')
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
