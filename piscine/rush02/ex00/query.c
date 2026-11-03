/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:17:12 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/02 19:18:59 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "query.h"
#include <unistd.h>

int	skip_middle_entry(char **nums, int nums_index, int char_index)
{
	while (nums[nums_index][char_index] >= '0'
			&& nums[nums_index][char_index] <= '9')
		char_index++;
	while (nums[nums_index][char_index] >= ' '
			|| nums[nums_index][char_index] <= ':')
		char_index++;
	return (char_index);
}

int	query_dict(int fd, char **nums, int n_nums)
{
	char	*buf;
	int		malloc_tries;
	int		buf_read;
	int		nums_index;
	int		char_index;
	char	*str_result;

	while (nums_index < n_nums)
	{
		buf = malloc(sizeof(char) * buf_read)
			if (buf == NULL && malloc_tries > 100)
				return (0);
			else if (buf == NULL)
				continue ;
		read(fd, buf, buf_read);
		str_result = vi_strstr(buf, nums[nums_index]); //Try with space after num
		if (str_result == NULL )
		{
			str_result = vi_strstr(buf, nums[nums_index]); //Try with colon after num
			if (str_result == NULL )
			{
				buf_read += 20;
				continue ;
			}
		}
		char_index = skip_middle_entry(nums, nums_index, char_index);
			while (nums[nums_index][char_index] == '\n')
			{
				write(1, &nums[nums_index][char_index], 1);
				char_index++;
			}
		if (nums_index == n_nums - 1)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
	}
}
