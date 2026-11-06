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

static t_list	*vi_new_node(t_list *src_node, void *(*f)(void *),
	void (*del)(void *),
	t_list *start_node) {
	t_list		*new;
	void		*temp_content;

	temp_content = f(src_node->content);
	new = ft_lstnew(temp_content);
	if (!new)
	{
		del(temp_content);
		if (start_node)
			ft_lstclear(&start_node, del);
		return ((void *)0);
	}
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*new_cur;
	t_list		*old_cur;

	if (!lst || !f || !del)
		return ((void *)0);
	new = vi_new_node(lst, f, del, (void *)0);
	if (!new)
		return ((void *)0);
	old_cur = lst->next;
	while (old_cur)
	{
		new_cur = vi_new_node(old_cur, f, del, new);
		if (!new_cur)
			return ((void *)0);
		ft_lstadd_back(&new, new_cur);
		old_cur = old_cur->next;
	}
	return (new);
}
