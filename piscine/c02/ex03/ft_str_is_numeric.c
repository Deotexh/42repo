/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:18:21 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/20 15:27:22 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	is_only_numeric;
	int	i;

	i = 0;
	is_only_numeric = 1;
	while (str[i] != '\0' && is_only_numeric == 1)
	{
		if (str[i] > '9' || str[i] < '0')
			is_only_numeric = 0;
		++i;
	}
	return (is_only_numeric);
}

/*
#include <stdio.h>
int	main()
{
	char str[] = "4191";
	printf("%d", ft_str_is_numeric(str));
	return 0;
}
*/
