/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:00:30 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/05 13:39:24 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	vi_base_validator(char *base_to_validate);
int	vi_handle_beginning(char *str, int *i);
int	vi_get_value(char *str, char *base, int i, int *has_failed);
int	vi_initialize_putnbr(int nbr, char **print_arr, char *base);

int	vi_handle_negative(int nbr, char *str)
{
	if (nbr < 0)
	{
		str[0] = '-';
		return (nbr * -1);
	}
	else
		return (nbr);
}

int	vi_ndigits(int nbr)
{
	int	result;

	result = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		result++;
	}
	return (result);
}

void	vi_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*vi_putnbr_base(int nbr, char *base, int sign)
{
	int		base_ndigits;
	int		temp;
	int		size;
	int		i;
	char	*print_arr;

	base_ndigits = vi_initialize_putnbr(nbr, &print_arr, base);
	if (base_ndigits == -1 || print_arr == NULL)
		return (NULL);
	i = -1;
	nbr = vi_handle_negative(nbr, print_arr);
	size = 0;
	if (nbr == 0)
		print_arr[0] = '0';
	while (nbr > 0)
	{
		temp = nbr % base_ndigits;
		print_arr[++i + (sign < 0)] = base[temp];
		size++;
		nbr /= base_ndigits;
	}
	i = -1;
	while (++i < ((size - 1) / 2))
		vi_swap(&print_arr[i + (sign < 0)], &print_arr[size - i - (sign > 0)]);
	return (print_arr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		i;
	int		num;
	int		has_failed;
	char	*result;

	i = 0;
	has_failed = 0;
	if (vi_base_validator(base_from) == -1)
		return (NULL);
	sign = vi_handle_beginning(nbr, &i);
	num = (vi_get_value(nbr, base_from, i, &has_failed) * sign);
	if (has_failed == 1)
		return (NULL);
	result = vi_putnbr_base(num, base_to, sign);
	return (result);
}

// #include <stdio.h>
// int main()
// {
// 	char base_from[] = "0123456789ABCDEF";
// 	char base_to[] = "0123456789";
// 	printf("%s\n", ft_convert_base("FF", base_from, base_to));
// 	printf("%s\n", ft_convert_base("-", base_from, base_to));
// }
