/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:05:33 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/15 16:59:33 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Comparing two integers */

int	intcmp(int n1, int n2)
{
	if (n1 == n2)
		return (0);
	else if (n1 < n2)
		return (1);
	else
		return (-1);
}

/* Clear stack A & B if there are allocated nodes */

void	free_data(t_list **stack_a, t_list **stack_b, char **arr)
{
	t_list	*tmp;
	t_list	*to_free;

	if (arr != NULL)
		ft_memfreeall((void **)arr);
	to_free = *stack_a;
	while (to_free != NULL)
	{
		tmp = to_free->next;
		ft_memfree((void *)to_free->content);
		ft_memfree((void *)to_free);
		to_free = tmp;
	}
	to_free = *stack_b;
	while (to_free != NULL)
	{
		tmp = to_free->next;
		ft_memfree((void *)to_free->content);
		ft_memfree((void *)to_free);
		to_free = tmp;
	}
}

/*	Print Error and free everything */

int	ft_error_free(t_list **stack_a, t_list **stack_b, char **arr)
{
	free_data(stack_a, stack_b, arr);
	ft_putstr_fd("Error\n", 1);
	return (-1);
}

/*	Long Long version of ft_atoi to handle bigger numbers */

long long	ft_atoi_ll(char *str)
{
	size_t			sign;
	size_t			i;
	long long		result;

	sign = 0;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign++;
		i++;
	}
	while (str[i] == 48)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + ((str[i] - 48) % 10);
		i++;
	}
	if (sign % 2 == 1)
		return (result * (-1));
	return (result);
}

/* Check if the stack is already sorted */

bool	is_sorted(t_list *stack)
{
	t_list	*n1;
	t_list	*n2;
	int		a;
	int		b;

	n1 = stack;
	n2 = stack->next;
	while (n1 != NULL)
	{
		while (n2 != NULL)
		{
			a = *(n1->content);
			b = *(n2->content);
			if (intcmp(a, b) != 1 && n1 != n2)
				return (false);
			n2 = n2->next;
		}
		n1 = n1->next;
		n2 = n1;
	}
	return (true);
}
