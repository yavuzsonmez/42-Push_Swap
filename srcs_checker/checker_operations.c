/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:39:14 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/14 10:44:31 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*	Execute the operation read on STDIN without printing */

static void	checker_swap(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == SA)
		swap(stack_a, len);
	else if (op == SB)
		swap(stack_b, len);
	else if (op == SS)
	{
		if (len->a > 1 && len->b > 1)
		{
			swap(stack_a, len);
			swap(stack_b, len);
		}
	}
}

static void	checker_push(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == PA)
	{
		push(stack_b, stack_a);
		++len->a;
		--len->b;
	}
	else if (op == PB)
	{
		push(stack_a, stack_b);
		--len->a;
		++len->b;
	}
}

static void	checker_rot(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == RA)
		rotate(stack_a);
	else if (op == RB)
		rotate(stack_b);
	else if (op == RR)
	{
		if (len->a > 1 && len->b > 1)
		{
			rotate(stack_a);
			rotate(stack_b);
		}
	}
}

static void	checker_rrot(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == RRA)
		rev_rotate(stack_a);
	else if (op == RRB)
		rev_rotate(stack_b);
	else if (op == RRR)
	{
		if (len->a > 1 && len->b > 1)
		{
			rev_rotate(stack_a);
			rev_rotate(stack_b);
		}
	}
}

void	checker(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == SA || op == SB || op == SS)
		checker_swap(stack_a, stack_b, len, op);
	else if (op == PA || op == PB)
		checker_push(stack_a, stack_b, len, op);
	else if (op == RA || op == RB || op == RR)
		checker_rot(stack_a, stack_b, len, op);
	else if (op == RRA || op == RRB || op == RRR)
		checker_rrot(stack_a, stack_b, len, op);
}
