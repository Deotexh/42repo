/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:18:21 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/20 15:28:59 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	is_only_uppercase;
	int	i;

	i = 0;
	is_only_uppercase = 1;
	while (str[i] != '\0' && is_only_uppercase == 1)
	{
		if (str[i] > 'Z' || str[i] < 'A')
			is_only_uppercase = 0;
		++i;
	}
	return (is_only_uppercase);
}

/*
#include <stdio.h>
int	main()
{
	char str[] = "4191";
	printf("%d", ft_str_is_uppercase(str));
	return 0;
}
*/
