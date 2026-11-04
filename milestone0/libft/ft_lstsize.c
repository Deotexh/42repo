/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:43:54 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/04 18:21:51 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int count;
	t_list		*current;

	if (!lst)
		return (0);
	current = lst;
	count = 1;
	while (current->next)
	{
		current = current->next;
		count++;
	}
	return (count);
}
