/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:20:03 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/14 10:54:42 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	Compare if the actual content is bigger
*	than all the content of the stack
*/

int	bigger_than_stack(t_list **stack_a, int number)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (*tmp->content < number)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

/*	Compare if the actual content is smaller
*	than all the contents of the stack
*/

int	smaller_than_stack(t_list **stack_a, int number)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (*tmp->content > number)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

/*	Find the index of the smallest number in the stack */

int	find_smallest(t_list **stack)
{
	int		i;
	t_list	*current;
	t_list	*tmp;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		tmp = *stack;
		while (tmp != NULL)
		{
			if (current == tmp)
				tmp = tmp->next;
			else if (*current->content < *tmp->content)
				tmp = tmp->next;
			else
				break ;
			if (tmp == NULL)
				return (i);
		}
		current = current->next;
		i++;
	}
	return (-1);
}

/*	Find the index of the biggest number in the stack */

int	find_biggest(t_list **stack)
{
	int		i;
	t_list	*current;
	t_list	*tmp;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		tmp = *stack;
		while (tmp != NULL)
		{
			if (current == tmp)
				tmp = tmp->next;
			else if (*current->content > *tmp->content)
				tmp = tmp->next;
			else
				break ;
			if (tmp == NULL)
				return (i);
		}
		current = current->next;
		i++;
	}
	return (-1);
}
