/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeyer-s <vmeyer-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:26:13 by vmeyer-s          #+#    #+#             */
/*   Updated: 2022/02/25 12:21:08 by vmeyer-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* takes (lst) and applies the (f) on the content of each node */
/* creates a new list of the successive applications of (f) */
/* the (del) is used to delete the content of a node */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*box;
	t_list	*mem;

	box = NULL;
	if (!lst)
		return (0);
	while (lst)
	{
		mem = ft_lstnew(f(lst->content));
		if (!mem)
		{
			ft_lstclear(&box, del);
			return (0);
		}
		ft_lstadd_back(&box, mem);
		lst = lst->next;
	}
	return (box);
}
