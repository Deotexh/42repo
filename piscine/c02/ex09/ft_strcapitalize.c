/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:57:50 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/21 10:44:08 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	vi_chupcase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
	}
}

void	vi_chlowcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
	{
		*c += 32;
	}
}

int	vi_is_alphanumeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((vi_is_alphanumeric(str[i - 1]) == 0) || (i == 0))
			vi_chupcase(&str[i]);
		else
			vi_chlowcase(&str[i]);
		++i;
	}
	return (str);
}

/*
#include <stdio.h>
int	main()
{
char str[] = "hi, how are you? 42words forty-two; fifty+and+one";
printf("%s", ft_strcapitalize(str));
return 0;
}
*/
