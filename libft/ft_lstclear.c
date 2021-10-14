/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:24:32 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/13 15:08:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*rm;

	tmp = *lst;
	while (tmp != NULL)
	{
		rm = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = rm;
	}
	*lst = NULL;
}
