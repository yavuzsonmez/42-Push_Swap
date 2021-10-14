/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:27:50 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/11 16:29:14 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	Process the markup by greater than for a specific markup_head
*	markup_head is the adress of an element in stack A which is the starting
*	point of the markup
*/

static void	markup_by_greater_than(t_list *markup_head)
{
	t_list	*gt;
	t_list	*tmp;

	markup_head->mgt = true;
	gt = markup_head;
	tmp = markup_head->next;
	while (*tmp->content != *markup_head->content)
	{
		if (*tmp->content > *gt->content)
		{
			tmp->mgt = true;
			gt = tmp;
		}
		else
			tmp->mgt = false;
		tmp = tmp->next;
	}
}

/*	Process the markup by index for a specific markup_head
*	markup_head is the adress of an element in stack A which is the starting
*	point of the markup
*/

static void	markup_by_index(t_list *markup_head)
{
	t_list	*gt;
	t_list	*tmp;

	markup_head->mi = true;
	gt = markup_head;
	tmp = markup_head->next;
	while (tmp != markup_head)
	{
		if (tmp->i == gt->i + 1)
		{
			tmp->mi = true;
			gt = tmp;
		}
		else
			tmp->mi = false;
		tmp = tmp->next;
	}
}

/*	Count the number of true after both markup
*	for a specific element as head and store the data
*	arr[1] == number of true for the markup greater than
				for a specific element as head_markup
*	arr[2] == number of true for the markup by index
				for a specific element as head_markup
*/

void	count_true(t_list **stack_a, t_len *len, int *arr)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	arr[1] = 0;
	arr[2] = 0;
	while (i < len->a)
	{
		if (tmp->mgt == true)
			arr[1]++;
		if (tmp->mi == true)
			arr[2]++;
		tmp = tmp->next;
		i++;
	}
}

/*	Apply both markup (by index and by greater than) to all
*	element in stack A for each element as markup_head
*	and keep the best markup for the best element as head
*/

int	get_markup(t_list **stack_a, t_len *len, int *arr, int *markup)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	link_tail_to_head(stack_a);
	init_markup(markup);
	while (i < len->a)
	{
		arr[0] = i;
		markup_by_greater_than(tmp);
		markup_by_index(tmp);
		count_true(stack_a, len, arr);
		fill_markup_if_better(arr, markup);
		tmp = tmp->next;
		i++;
	}
	unlink_tail_to_head(stack_a, len);
	if (markup[2] >= markup[1])
		return (markup[2]);
	else
		return (markup[1]);
}

/* Apply a specific markup for a specific element as head */

void	get_specific_markup(t_list **stack_a, t_len *len, int *markup)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (i < markup[0])
	{
		tmp = tmp->next;
		i++;
	}
	link_tail_to_head(stack_a);
	if (markup[2] >= markup[1])
		markup_by_index(tmp);
	else
		markup_by_greater_than(tmp);
	unlink_tail_to_head(stack_a, len);
	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (markup[2] >= markup[1])
			tmp->mf = tmp->mi;
		else
			tmp->mf = tmp->mgt;
		tmp = tmp->next;
	}
}
