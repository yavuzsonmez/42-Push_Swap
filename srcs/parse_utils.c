/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 13:57:50 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/14 10:52:32 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	Calculate and store the initial length of A and B */

void	get_stack_length(t_list **stack_a, t_list **stack_b, t_len *len)
{
	len->a = ft_lstsize(*stack_a);
	len->b = ft_lstsize(*stack_b);
}

/* Check if there is two time the same integer in the list */

int	ft_check_duplicate(t_list *stack)
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
			if (!intcmp(a, b) && n1 != n2)
				return (0);
			n2 = n2->next;
		}
		n1 = n1->next;
		n2 = stack;
	}
	return (1);
}

/*
*	Parse input : separate gathered number (between quotes)
*	into single numbers;
*/

char	**ft_parser(char **argv, int i, int k)
{
	char	**arr;
	char	*tmp;
	char	*tmp2;
	char	*str;

	str = ft_strdup("");
	while (argv[i] != NULL)
	{
		arr = ft_split(argv[i], ' ');
		k = 0;
		while (arr[k] != NULL)
		{
			tmp = ft_strjoin(arr[k], ",");
			tmp2 = str;
			str = ft_strjoin(tmp2, tmp);
			k++;
			ft_memfree((void *)tmp);
			ft_memfree((void *)tmp2);
		}
		ft_memfreeall((void **)arr);
		i++;
	}
	arr = ft_split(str, ',');
	ft_memfree((void *)str);
	return (arr);
}
