/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:35:17 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/28 13:25:58 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	vi_get_value(char *str, char *base, int i, int base_len)
{
	int	base_srch_i;
	int	pow;
	int	result;
	int	temp_i;

	result = 0;
	temp_i = i;
	while (str[temp_i] != '\0')
		temp_i++;
	pow = (temp_i - 1) - i;
	while (str[i] != '\0')
	{
		base_srch_i = 0;
		while (1)
		{
			if (str[i] == base[base_srch_i])
				break ;
			else if (base_srch_i >= base_len)
				return (result);
			base_srch_i++;
		}
		result = (result * base_len) + base_srch_i;
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	i;
	int	result;
	int	base_len;

	result = 0;
	base_len = vi_base_validator(base);
	if (base_len == -1)
		return (0);
	sign = vi_handle_beginning(str, &i);
	result = vi_get_value(str, base, i, base_len);
	return (result * sign);
}

// #include <stdio.h>
// int	main()
// {
// 	int	result = ft_atoi_base("FoF", "0123456789ABCDEF");
// 	printf("Result is: %d", result);
// }
