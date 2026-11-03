/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:06:22 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/28 12:34:21 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	vi_base_validator(char *base_to_validate)
{
	int		len;
	int		i;

	len = -1;
	while (base_to_validate[++len] != '\0')
	{
		if (base_to_validate[len] == '-' || base_to_validate[len] == '+')
			return (-1);
		i = len;
		while (base_to_validate[++i] != '\0')
		{
			if (base_to_validate[i] == base_to_validate[len])
				return (-1);
		}
	}
	if (len <= 1)
		return (-1);
	return (len);
}

int	vi_handle_negative(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (nbr *= -1);
	}
	else
		return (nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_ndigits;
	int		temp;
	int		size_of_print;
	int		i;
	char	print_arr[100];

	i = -1;
	size_of_print = 0;
	base_ndigits = vi_base_validator(base);
	if (base_ndigits == -1)
		return ;
	nbr = vi_handle_negative(nbr);
	while (nbr > 0)
	{
		temp = nbr % base_ndigits;
		print_arr[++i] = base[temp];
		size_of_print++;
		nbr /= base_ndigits;
	}
	while (size_of_print > 0)
	{
		write(1, &print_arr[size_of_print - 1], 1);
		size_of_print--;
	}
}

// #include <stdio.h>
// int	main()
// {
// 	int num = -1992;
// 	char *base = "0123";
// 	printf("Result of base validator: %d\n", base_validator(base));
// 	printf("Result of vi_handle_negative: %d\n", vi_handle_negative(num));
// 	printf("Result of ft_putnbr_base:\n\n");
// 	ft_putnbr_base(num, base);
// }
