/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:30:52 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/02 18:53:19 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

static int	vi_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	vi_handle_beginning(const char *nptr, int *sign)
{
	int	i;
	
	i = 0;
	*sign = 1;
	while (vi_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] == '0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long	result;
	int	sign;
	int	i;
	int	first_d;

	if (!nptr)
		return (0);
	i = vi_handle_beginning(nptr, &sign);
	first_d = i;
	result = 0;
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	if (result > INT_MAX && sign == 1)
		return (INT_MAX);
	if (-result < INT_MIN && sign == -1)
		return (INT_MIN);
	return (result * sign);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	char *str = "a      2147483647";
// 	
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// }
