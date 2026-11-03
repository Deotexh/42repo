/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:28:38 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/02 19:31:53 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	vi_atoi(char *str)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	while (str[++i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		else if (result != 0)
			result = (result * 10) + (str[i] - '0');
		else
			result = str[i] - '0';
	}
	return (result);
}

int	ipow(int base, int exp)
{
	int	initial_base;

	initial_base = base;
	if (exp == 0)
		return (1);
	while (exp > 1)
	{
		base *= initial_base;
		--exp;
	}
	return (base);
}

char	*vi_strstr(char *str, char *to_find)
{
	int	compare_i;
	int	find_i;

	if (to_find[0] == '\0')
		return (str);
	find_i = -1;
	while (str[++find_i] != '\0')
	{
		compare_i = 0;
		if (str[find_i] != to_find[compare_i])
			continue ;
		while (to_find[compare_i] == str[find_i + compare_i])
		{
			if (to_find[compare_i + 1] == '\0')
				return (&str[find_i]);
			compare_i++;
		}
	}
	return ((void *)0);
}
