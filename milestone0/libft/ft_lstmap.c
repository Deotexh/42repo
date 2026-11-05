/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:22:02 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/04 18:40:01 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*new_cur;
	t_list		*old_cur;
	void		*temp_content;

	if (!lst || !f || !del)
		return ((void *)0);
	temp_content = f(lst->content);
	new = ft_lstnew(temp_content);
	if (!new)
	{
		del(temp_content);
		return((void *)0);
	}
	old_cur = lst->next;
	while (old_cur)
	{
		temp_content = f(old_cur->content);
		new_cur = ft_lstnew(temp_content);
		if (!new_cur)
		{
			del(temp_content);
			ft_lstclear(&new, del);
			return ((void *)0);
		}
		ft_lstadd_back(&new, new_cur);
		old_cur = old_cur->next;
	}
	return (new);
}

