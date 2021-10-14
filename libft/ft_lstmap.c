/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:24:48 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/13 15:09:41 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*nlist;

	head = NULL;
	while (lst != NULL)
	{
		nlist = ft_lstnew(f(lst->content));
		if (nlist == NULL)
			ft_lstclear(&nlist, del);
		else
			ft_lstadd_back(&head, nlist);
		lst = lst->next;
	}
	return (head);
}
