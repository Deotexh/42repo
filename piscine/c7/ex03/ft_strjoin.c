/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:13:22 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/30 20:16:27 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*vi_handle_size_zero(void)
{
	char	*str;

	str = malloc(sizeof(char));
	str[0] = '\0';
	return (str);
}

void	vi_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return ;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	size_t	malloc_size;

	str = NULL;
	malloc_size = -1;
	i = -1;
	if (size == 0)
		return (vi_handle_size_zero());
	while (++i < size)
		malloc_size += sizeof(strs[i]);
	while (str == NULL)
		str = malloc(malloc_size);
	str[0] = '\0';
	i = -1;
	while (++i < size)
	{
		vi_strcat(str, strs[i]);
		if (i != size - 1)
			vi_strcat(str, sep);
	}
	return (str);
}

// #include <unistd.h>
// #include <stdio.h>
// int main ()
// {
// 	char sep[] = "AAAAAA";
// 	char *arr[] = {"Hallo, ", "mon", " gey!"};
// 	printf("%lu\n", sizeof(arr));
// 	char *str = ft_strjoin(0, arr, sep);
// 	printf("%s", str);
// }
