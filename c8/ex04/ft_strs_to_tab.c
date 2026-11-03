/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 12:30:02 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/03 16:29:36 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	vi_strlen(char *str)
{
	int	total_len;

	total_len = 0;
	while (str[total_len] != '\0')
		total_len++;
	return (total_len);
}

char	*vi_create_cpy(char *str)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char) * (vi_strlen(str) + 1));
	if (cpy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	vi_free_all(t_stock_str *arr, int arr_i)
{
	arr_i--;
	while (arr_i >= 0)
	{
		free (arr[arr_i].copy);
	}
	free (arr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			arr_i;
	char		*current_cpy;

	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == NULL)
		return (NULL);
	arr_i = 0;
	while (arr_i < ac)
	{
		current_cpy = vi_create_cpy(av[arr_i]);
		if (current_cpy == NULL)
		{
			vi_free_all(arr, arr_i);
			return (NULL);
		}
		arr[arr_i].size = vi_strlen(av[arr_i]);
		arr[arr_i].str = av[arr_i];
		arr[arr_i].copy = current_cpy;
		arr_i++;
	}
	arr[arr_i].size = 0;
	arr[arr_i].str = 0;
	arr[arr_i].copy = 0;
	return (arr);
}
