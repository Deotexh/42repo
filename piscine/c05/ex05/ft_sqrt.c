/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:03:53 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/30 19:14:03 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	i = 0;
	while (i < nb)
	{
		if (i * i == nb)
			return (i);
		else if ((nb < i * i) && (nb > (i - 1) * (i - 1)))
			return (0);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d", ft_sqrt(4));
// }
