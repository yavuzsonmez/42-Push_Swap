/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:24:54 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/09 11:54:30 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	Take the first element at the top of stack 1
*	and put it at the top of stack 2. Do nothing if stack 1 is empty
*/

int	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (*stack_1 == NULL)
		return (0);
	tmp = *stack_1;
	*stack_1 = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_2, tmp);
	return (1);
}

/*
*	Swap the first 2 elements at the top of given stack
*	Do nothing if there is only one or no elements
*/

int	swap(t_list **stack, t_len *len)
{
	t_list	*tmp;
	t_list	*swp;

	if (len->a < 2)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	swp = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->next = swp;
	return (1);
}

/*
*	Shift UP all elements of given stack by 1
*	The first element becomes the last one
*	Do nothing if there is only one or no elements
*/

int	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*swp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = *stack;
	swp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	*stack = swp->next;
	swp->next = NULL;
	tmp->next = swp;
	return (1);
}

/*
*	Shift DOWN all elements of stack by 1
*	The first element becomes the last one
*	Do nothing if there is only one or no elements
*/

int	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*swp;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = *stack;
	swp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	*stack = tmp->next;
	tmp->next->next = swp;
	tmp->next = NULL;
	return (1);
}
