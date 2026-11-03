/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:46:38 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/20 12:56:48 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// int	main()
// {
// 	char str[] = "Hello, World!";
// 	char dest[13];
//
//
// 	printf("Before: %s\n", dest);
// 	printf("After: %s\n", ft_strcpy(dest, str));
// 	return 0;
// }
