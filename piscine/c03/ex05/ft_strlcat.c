/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:16:08 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/01 14:30:58 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	vi_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	int				is_dest_nullterminated;

	is_dest_nullterminated = 0;
	i = -1;
	while (++i < size)
	{
		if (dest[i] == '\0')
			is_dest_nullterminated = 1;
	}
	dest_len = vi_strlen(dest);
	if (is_dest_nullterminated == 0 || size < 1)
		return (dest_len + vi_strlen(src));
	if (size <= dest_len)
		return (dest_len + vi_strlen(src));
	i = -1;
	while (++i < (size - dest_len - 1))
		dest[i + dest_len] = src[i];
	dest[i] = '\0';
	return (dest_len + vi_strlen(src));
}

// #include <bsd/string.h>
// #include <stdio.h>
// int main(void)
// {
// 	char dest[8] = "H";
// 	char dest2[8] = "H";
// 	char src[] = "lo";
// 	unsigned int result;
// 	unsigned int size = 7;
// 	unsigned int i = 0;
//
// 	result = ft_strlcat(dest, src, size);
// 	printf("Ft result: ");
// 	while (i < size)
// 	{
// 		if (dest[i] < 32)
// 			printf("%d ", dest[i]);
// 		else
// 			printf("%c ", dest[i]);
// 		i++;
// 	}
// 	printf(" with %u\n", result);
// 	i = 0;
// 	result = strlcat(dest2, src, size);
// 	printf("Original result: ");
// 	while (i < size)
// 	{
// 		if (dest[i] < 32)
// 			printf("%d ", dest[i]);
// 		else
// 			printf("%c ", dest[i]);
// 		i++;
// 	}
// 	printf(" with %u\n", result);
// }
