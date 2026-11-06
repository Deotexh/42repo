/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:54:23 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/04 10:54:23 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	vi_count_substr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			count++;
		i++;
	}
	return (count);
}

static void	vi_free_all(char **array, int arr_i)
{
	while (arr_i >= 0)
	{
		free(array[arr_i]);
		arr_i--;
	}
	free(array);
}

static char	*vi_get_split(char const *s, char c, int *i)
{
	char	*ptr;
	int		start;
	int		write_i;

	start = *i;
	while (s[*i] != c && s[*i] != '\0')
		*i += 1;
	ptr = malloc(*i - start + 1);
	if (!ptr)
		return ((void *)0);
	write_i = 0;
	while (start < *i)
	{
		ptr[write_i] = s[start];
		write_i++;
		start++;
	}
	ptr[write_i] = '\0';
	return (ptr);
}

static int	vi_init(char const *s, char c, char ***array)
{
	if (!s)
		return (0);
	*array = malloc((vi_count_substr(s, c) + 1) * sizeof(char *));
	if (!(*array))
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*temp_i;
	int		arr_i;
	int		str_i;

	if (!vi_init(s, c, &array))
		return ((void *)0);
	arr_i = 0;
	str_i = 0;
	while (s[str_i] != '\0')
	{
		while (s[str_i] == c)
			str_i++;
		if (s[str_i] == '\0')
			break ;
		temp_i = vi_get_split(s, c, &str_i);
		if (!temp_i)
		{
			vi_free_all(array, arr_i - 1);
			return ((void *)0);
		}
		array[arr_i++] = temp_i;
	}
	array[arr_i] = (void *)0;
	return (array);
}
