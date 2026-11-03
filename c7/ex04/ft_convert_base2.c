/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:37:41 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/05 13:38:29 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	vi_ndigits(int nbr);

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

int	vi_handle_beginning(char *str, int *i)
{
	int	sign;
	int	local_i;

	sign = 1;
	local_i = 0;
	while ((str[local_i] == ' ') || (str[local_i] == '\f')
		|| (str[local_i] == '\n') || (str[local_i] == '\r')
		|| (str[local_i] == '\v') || (str[local_i] == '\t'))
		local_i++;
	while (str[local_i] == '+' || str[local_i] == '-')
	{
		if (str[local_i] == '-')
			sign *= -1;
		local_i++;
	}
	*i = local_i;
	return (sign);
}

int	vi_get_value(char *str, char *base, int i, int *has_failed)
{
	int	base_srch_i;
	int	result;
	int	base_len;

	base_len = vi_base_validator(base);
	result = 0;
	i -= 1;
	while (str[++i] != '\0')
	{
		base_srch_i = 0;
		while (1)
		{
			if (str[i] == base[base_srch_i])
				break ;
			else if (base_srch_i >= base_len)
			{
				*has_failed = 1;
				return (result);
			}
			base_srch_i++;
		}
		result = (result * base_len) + base_srch_i;
	}
	return (result);
}

int	vi_initialize_putnbr(int nbr, char **print_arr, char *base)
{
	*print_arr = malloc(sizeof(char) * (vi_ndigits(nbr) + (nbr < 0)));
	return (vi_base_validator(base));
}
