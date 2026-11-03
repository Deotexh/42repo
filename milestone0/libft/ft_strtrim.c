/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:45:31 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/03 17:53:22 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	vi_setcheck(char const c, char const *set)
{
	int i;
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return(0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char *new_str;
	int len;
	int i;

	len = 0;
	i = 0;
	while (!s1[i])
	{
		if (vi_setcheck(s1[i]))
			len++;
		i++;
	}
	new_str = malloc()
		if (!s1 || !new_str)
			return ((void *)0);

}
