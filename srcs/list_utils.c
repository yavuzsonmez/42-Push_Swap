/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 13:44:51 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/15 16:56:25 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Link the end of linked list to the beginning
*	in order to be able to re-itarate (circle)
*/

void	link_tail_to_head(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
}

/*	Unlink the end of the linked list with the beginning
*	Change it to his initial state
*/

void	unlink_tail_to_head(t_list **stack, t_len *len)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (i < len->a - 1)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
}

/*	Verify each parsed arg in the array before creating the list
*	Should be a number, with or without sign
*/

static int	parse_each_input(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

/*	Create the stack A base on args (parameters)
*	Verify if numeric, consider the sign
*	Check the range of the number, only INT range is considered
*	Create new allocated node
*	Add the new node to the end of the linked list
*/

t_list	*ft_create_stack_a(char **argv, int i)
{
	long long	*number;
	t_list		*stack_a;
	t_list		*new_elem;

	stack_a = NULL;
	while (argv[i] != NULL)
	{
		if (!(parse_each_input(argv[i])))
			return (NULL);
		number = (long long *)malloc(sizeof(long long));
		if (number == NULL)
			return (NULL);
		*number = ft_atoi_ll(argv[i]);
		if (*number < -2147483648 || *number > 2147483647)
			return (NULL);
		new_elem = ft_lstnew(number);
		if (new_elem == NULL)
			return (NULL);
		ft_lstadd_back(&stack_a, new_elem);
		i++;
	}
	return (stack_a);
}
