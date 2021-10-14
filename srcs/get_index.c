/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:11:10 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/14 10:54:29 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	Copy the content of the linked list in an stati array */

static void	cpy_lst_to_arr(t_list **stack_a, t_len *len, int *arr)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	while (i < len->a)
	{
		arr[i] = *tmp->content;
		tmp = tmp->next;
		i++;
	}
}

/*	Bubble sort the array */

static void	sort_arr(int *arr, t_len *len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len->a)
	{
		j = i + 1;
		if (j < len->a && arr[i] > arr[j])
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i = -1;
		}
		i++;
	}
}

/*	Find the index of each content of each node after beeing sorted */

void	get_index(t_list **stack_a, t_len *len, int i)
{
	int		*arr;
	t_list	*tmp;

	tmp = *stack_a;
	arr = (int *)malloc(sizeof(int) * len->a);
	if (arr == NULL)
		exit(EXIT_FAILURE);
	cpy_lst_to_arr(stack_a, len, arr);
	sort_arr(arr, len);
	while (tmp != NULL)
	{
		i = 0;
		while (i < len->a)
		{
			if (arr[i] == *tmp->content)
			{
				tmp->i = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	ft_memfree((void *)arr);
}
