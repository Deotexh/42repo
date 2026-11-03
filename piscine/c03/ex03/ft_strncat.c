/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:16:08 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/23 21:12:08 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (i < nb)
	{
		if (src[i] == '\0')
			break ;
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char str1[] = "Hello,";
// 	char str2[] = "Hello,";
// 	char str3[] = "World!";
//
// 	printf("Ft result: %s\n", ft_strncat(str1, str3, 100));
// 	printf("Original result: %s\n", strncat(str2, str3, 100));
// }
