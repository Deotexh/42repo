/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:18:21 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/20 15:36:57 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	is_only_printable;
	int	i;

	i = 0;
	is_only_printable = 1;
	while (str[i] != '\0' && is_only_printable == 1)
	{
		if (str[i] < 32 || str[i] == 127)
			is_only_printable = 0;
		++i;
	}
	return (is_only_printable);
}

/*
#include <stdio.h>
int	main()
{
	char str[] = "\n  4191";
	printf("%d", ft_str_is_printable(str));
	return 0;
}
*/
