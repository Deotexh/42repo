/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:19:22 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/20 15:19:28 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	is_only_alphabetical;
	int	i;

	i = 0;
	is_only_alphabetical = 1;
	while (str[i] != '\0' && is_only_alphabetical == 1)
	{
		if (str[i] > 'z')
			is_only_alphabetical = 0;
		else if (str[i] > 'Z' && str[i] < 'a')
			is_only_alphabetical = 0;
		else if (str[i] < 'A')
			is_only_alphabetical = 0;
		++i;
	}
	return (is_only_alphabetical);
}

/*
#include <stdio.h>
int	main()
{
	char str[] = "";
	printf("%d", ft_str_is_alpha(str));
	return 0;
}
*/
