/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:42:20 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/27 17:05:01 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	vi_str_is_numeric(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

int	vi_is_space(char c)
{
	if ((c == ' ') || (c == '\f') || (c == '\n') || (c == '\r')
		|| (c == '\v') || (c == '\t'))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	skipping_space;
	int	n_minus_sign;
	int	i;
	int	result;

	i = -1;
	n_minus_sign = 1;
	skipping_space = 1;
	result = 0;
	while (str[++i] != '\0')
	{
		if (!vi_is_space(str[i]))
			skipping_space = 0;
		if (((vi_is_space(str[i])) && (skipping_space == 1)) || (str[i] == '+'))
			continue ;
		else if (str[i] == '-')
			n_minus_sign *= -1;
		else if (vi_str_is_numeric(str[i]) == 1 && result == 0)
			result = str[i] - '0';
		else if (vi_str_is_numeric(str[i]) == 1 && result != 0)
			result = (result * 10) + (str[i] - '0');
		else
			break ;
	}
	return (result * n_minus_sign);
}

// #include <stdio.h>
// int	main()
// {
// 	int result = ft_atoi("       -++123456q964");
// 	printf("%d", result);
// }
