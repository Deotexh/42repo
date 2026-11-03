/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:06:55 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/21 10:58:18 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	vi_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return (len);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	src_size;

	i = 0;
	src_size = vi_strlen(src);
	while (i < n)
	{
		if (i < src_size)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		++i;
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char str[] = "Hello,";
// 	char dest[13] = "";
// 	char dest2[13] = "";
//
//
// 	printf("--Custom\n");
// 	printf("Before: %s\n", dest);
// 	ft_strncpy(dest, str, 10);
// 	printf("After: %s\n\n", dest);
// 	printf("--Original\n");
// 	printf("Before: %s\n", dest2);
// 	strncpy(dest2, str, 10);
// 	printf("After: %s\n", dest2);
// 	return 0;
// }
