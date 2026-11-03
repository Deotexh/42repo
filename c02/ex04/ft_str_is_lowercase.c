/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:18:21 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/20 15:29:10 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	is_only_lowercase;
	int	i;

	i = 0;
	is_only_lowercase = 1;
	while (str[i] != '\0' && is_only_lowercase == 1)
	{
		if (str[i] > 'z' || str[i] < 'a')
			is_only_lowercase = 0;
		++i;
	}
	return (is_only_lowercase);
}

/*
#include <stdio.h>
int	main()
{
	char str[] = "asddhasodQ";
	printf("%d", ft_str_is_lowercase(str));
	return 0;
}
*/
