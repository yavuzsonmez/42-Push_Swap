/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:29:39 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/14 10:53:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	Norm, operations, updating length, printing */

static void	op_swap(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == SA)
	{
		if (swap(stack_a, len))
			ft_putstr_fd("sa\n", 1);
	}
	else if (op == SB)
	{
		if (swap(stack_b, len))
			ft_putstr_fd("sb\n", 1);
	}
	else if (op == SS)
	{
		if (len->a > 1 && len->b > 1)
		{
			if (swap(stack_a, len) && swap(stack_b, len))
				ft_putstr_fd("ss\n", 1);
		}
	}
}

static void	op_push(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == PA)
	{
		if (push(stack_b, stack_a))
		{
			++len->a;
			--len->b;
			ft_putstr_fd("pa\n", 1);
		}
	}
	else if (op == PB)
	{
		if (push(stack_a, stack_b))
		{
			--len->a;
			++len->b;
			ft_putstr_fd("pb\n", 1);
		}
	}
}

static void	op_rotate(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == RA)
	{
		if (rotate(stack_a))
			ft_putstr_fd("ra\n", 1);
	}
	else if (op == RB)
	{
		if (rotate(stack_b))
			ft_putstr_fd("rb\n", 1);
	}
	else if (op == RR)
	{
		if (len->a > 1 && len->b > 1)
		{
			if (rotate(stack_a) && rotate(stack_b))
				ft_putstr_fd("rr\n", 1);
		}
	}
}

static void	op_rrotate(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == RRA)
	{
		if (rev_rotate(stack_a))
			ft_putstr_fd("rra\n", 1);
	}
	else if (op == RRB)
	{
		if (rev_rotate(stack_b))
			ft_putstr_fd("rrb\n", 1);
	}
	else if (op == RRR)
	{
		if (len->a > 1 && len->b > 1)
		{
			if (rev_rotate(stack_a) && rev_rotate(stack_b))
				ft_putstr_fd("rrr\n", 1);
		}
	}
}

void	operations(t_list **stack_a, t_list **stack_b, t_len *len, int op)
{
	if (op == SA || op == SB || op == SS)
		op_swap(stack_a, stack_b, len, op);
	else if (op == PA || op == PB)
		op_push(stack_a, stack_b, len, op);
	else if (op == RA || op == RB || op == RR)
		op_rotate(stack_a, stack_b, len, op);
	else if (op == RRA || op == RRB || op == RRR)
		op_rrotate(stack_a, stack_b, len, op);
}
