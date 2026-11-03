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

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	size_t i;

	if (!s)
		return ((void *)0);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
