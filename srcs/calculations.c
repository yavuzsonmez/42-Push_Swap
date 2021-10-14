/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:14:31 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/12 19:11:14 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	The number we want to push to A is smaller than all numbers in stack A
*			YES: data[0] == 1		NO: data[0] == 0;
*	The number we want to push to A is bigger than all numbers in stack A
*			YES: data[1] == 1		NO: data[1] == 0;
*	data[2] == index of the smallest number in stack A
*/

static void	is_smaller_or_bigger(t_list **stack, int number, int *data)
{
	data[0] = smaller_than_stack(stack, number);
	data[1] = bigger_than_stack(stack, number);
	data[2] = find_smallest(stack);
}

/*	Store the result (in an array)
*	of calculations of rotate A in order to push the number
*	from B to the right place in A
*/

static void	fill_data_r_a(t_len *len, int *arr, int i)
{
	if (i > (len->a / 2))
	{
		arr[1] = RRA;
		arr[2] = len->a - i;
	}
	else
	{
		arr[1] = RA;
		arr[2] = i;
	}
}

/*	Calculate the number of operations required to rotate stack A
*	in order to insert the number from stack B to stack A
*/

void	calculate_rot_a(t_list **stack_a, t_len *len, int number, int *arr)
{
	int		i;
	t_list	*tmp;
	t_list	*last;
	int		data[3];

	i = 0;
	tmp = *stack_a;
	last = ft_lstlast(*stack_a);
	if (number < *tmp->content && number > *last->content)
		return (fill_data_r_a(len, arr, i));
	is_smaller_or_bigger(stack_a, number, data);
	while (tmp->next != NULL)
	{
		if (number > *tmp->content && number < *tmp->next->content && ++i)
			break ;
		else if (data[0] && data[2] == i)
			break ;
		else if (data[1] && data[2] == i)
			break ;
		tmp = tmp->next;
		i++;
	}
	fill_data_r_a(len, arr, i);
}

/*	Calculate the number of operations required to rotate stack B
*	in order to insert the number from stack B to stack A
*	and store the data in an array
*/

void	calculate_rot_b(t_len *len, int i, int *arr)
{
	if (i > (len->b / 2))
	{
		arr[3] = RRB;
		arr[4] = len->b - i;
	}
	else
	{
		arr[3] = RB;
		arr[4] = i;
	}
}
