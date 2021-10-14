/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:22:21 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/11 16:24:44 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_markup(int *markup)
{
	markup[0] = 0;
	markup[1] = 0;
	markup[2] = 0;
}

/*	Replace the data about the most optimized markup
*	if the current one of the test markup in *arr
*	is better than previous markup (if more true, too keep in stack A)
*/

void	fill_markup_if_better(int *arr, int *markup)
{
	if (arr[1] > markup[1] && arr[1] > markup[2])
	{
		markup[0] = arr[0];
		markup[1] = arr[1];
		markup[2] = arr[2];
	}
	else if (arr[2] > markup[1] && arr[2] > markup[2])
	{
		markup[0] = arr[0];
		markup[1] = arr[1];
		markup[2] = arr[2];
	}
	else
		return ;
}

/*	During the first step (pushing B) after using the best markup
*	check if there is still an element marked as "false"
*/

int	check_false_markup(t_list **stack_a, t_len *len)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (i < len->a)
	{
		if (tmp->mf == false)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
