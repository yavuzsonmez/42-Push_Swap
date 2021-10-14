/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:46:55 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/12 19:14:37 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	Rotating Stack A and/or B depending of the collected data
*	Optimizations :
*		RA	&&	RB	==	RR
*		RRA	&&	RRB	==	RRR
*/

void	move_stacks(t_list **a, t_list **b, t_len *len, int *data)
{
	while (data[2] || data[4])
	{
		if (data[2] && data[4] && data[1] == RA && data[3] == RB)
		{
			operations(a, b, len, RR);
			data[2]--;
			data[4]--;
		}
		else if (data[2] && data[4] && data[1] == RRA && data[3] == RRB)
		{
			operations(a, b, len, RRR);
			data[2]--;
			data[4]--;
		}
		else if (data[2])
		{
			operations(a, b, len, data[1]);
			data[2]--;
		}
		else if (data[4])
		{
			operations(a, b, len, data[3]);
			data[4]--;
		}
	}
}

/* If data of calculation is more opti, fill the used array */

void	fill_array(int *opti, int *arr)
{
	opti[0] = arr[0];
	opti[1] = arr[1];
	opti[2] = arr[2];
	opti[3] = arr[3];
	opti[4] = arr[4];
}

/*
*	Main function to calculate and push back numbers from stack B
*	to the right place in stack A
*/

void	push_back(t_list **stack_a, t_list **stack_b, t_len *len)
{
	t_list	*tmp;
	int		i;
	int		arr[5];
	int		opti[5];

	while (*stack_b != NULL)
	{
		tmp = *stack_b;
		i = 0;
		opti[2] = INT_MAX / 3;
		opti[4] = INT_MAX / 3;
		while (i < len->b)
		{
			arr[0] = i;
			calculate_rot_a(stack_a, len, *tmp->content, arr);
			calculate_rot_b(len, i, arr);
			if (arr[2] + arr[4] < opti[2] + opti[4])
				fill_array(opti, arr);
			tmp = tmp->next;
			i++;
		}
		move_stacks(stack_a, stack_b, len, opti);
		operations(stack_a, stack_b, len, PA);
	}
}

/* Reorganize the actual sorted stack: put the smallest number to index 0 */

void	clear_stack(t_list **stack_a, t_list **stack_b, t_len *len)
{
	int	i;
	int	move;

	i = find_smallest(stack_a);
	if (i < (len->a / 2))
		move = RA;
	else
	{
		i = len->a - i;
		move = RRA;
	}
	while (i > 0)
	{
		operations(stack_a, stack_b, len, move);
		i--;
	}
}

/*
*	Sorting algorithm for inputs numbers > 5
*	-	Markup
*			markup[0] = markup_head index
*			markup[1] = number of true in a row for markup greater than
*			markup[2] = number of true in a row for markup by index
*	-	Push B  in order to let A sorted
	-	Calculate and push back A to the right place
*	-	Align stack A
*/

void	big_sort(t_list **stack_a, t_list **stack_b, t_len *len)
{
	int		arr[3];
	int		markup[3];
	t_list	*tmp;
	int		test;

	get_index(stack_a, len, 0);
	tmp = *stack_a;
	tmp->mf = false;
	get_markup(stack_a, len, arr, markup);
	get_specific_markup(stack_a, len, markup);
	test = check_false_markup(stack_a, len);
	while (test == 1)
	{
		tmp = *stack_a;
		if (tmp->mf == false)
			operations(stack_a, stack_b, len, PB);
		else
			operations(stack_a, stack_b, len, RA);
		test = check_false_markup(stack_a, len);
	}
	push_back(stack_a, stack_b, len);
	clear_stack(stack_a, stack_b, len);
}
