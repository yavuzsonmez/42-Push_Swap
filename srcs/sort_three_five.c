/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:58:35 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/11 10:49:47 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Enjoying the norm */

static void	fill_data(t_list **stack_a, t_len *len, int *arr)
{
	t_list	*tmp;

	tmp = *stack_a;
	arr[0] = *tmp->content;
	arr[1] = *tmp->next->content;
	if (len->a >= 3)
		arr[2] = *tmp->next->next->content;
}

/* Sort two or three element in a stack in 3 operations max */

static void	sort_three(t_list **stack_a, t_list **stack_b, t_len *len)
{
	int		arr[3];

	fill_data(stack_a, len, arr);
	if (len->a == 2 && arr[0] > arr[1])
		operations(stack_a, stack_b, len, SA);
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		operations(stack_a, stack_b, len, SA);
	else if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		operations(stack_a, stack_b, len, SA);
		operations(stack_a, stack_b, len, RRA);
	}
	else if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
		operations(stack_a, stack_b, len, RA);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
	{
		operations(stack_a, stack_b, len, SA);
		operations(stack_a, stack_b, len, RA);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		operations(stack_a, stack_b, len, RRA);
}

/* Sort four or five element in a stack in 12 operations max */

static void	sort_five(t_list **stack_a, t_list **stack_b, t_len *len)
{
	int	s;
	int	move;

	while (len->a > 3)
	{
		s = find_smallest(stack_a);
		if (s < (len->a / 2))
			move = RA;
		else
			move = RRA;
		while (s != 0)
		{
			operations(stack_a, stack_b, len, move);
			s = find_smallest(stack_a);
		}
		operations(stack_a, stack_b, len, PB);
	}
	sort_three(stack_a, stack_b, len);
	operations(stack_a, stack_b, len, PA);
	operations(stack_a, stack_b, len, PA);
}

/* Small sorting algorithm, sort stack under 6 inputs */

void	small_sort(t_list **stack_a, t_list **stack_b, t_len *len)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (len->a > 1 && len->a < 4)
	{
		if (len->a == 2 && *tmp->content < *tmp->next->content)
			return ;
		sort_three(stack_a, stack_b, len);
	}
	else
		sort_five(stack_a, stack_b, len);
}
