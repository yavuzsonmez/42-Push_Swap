/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:45:17 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/11 15:27:05 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_len	len;
	char	**parsed_args;

	if (argc < 2)
		return (-1);
	parsed_args = ft_parser(argv, 1, 0);
	stack_a = ft_create_stack_a(parsed_args, 0);
	stack_b = NULL;
	if (stack_a == NULL || !ft_check_duplicate(stack_a))
		return (ft_error_free(&stack_a, &stack_b, parsed_args));
	get_stack_length(&stack_a, &stack_b, &len);
	if (is_sorted(stack_a) == true)
	{
		free_data(&stack_a, &stack_b, parsed_args);
		return (0);
	}
	if (len.a > 1 && len.a < 6)
		small_sort(&stack_a, &stack_b, &len);
	else
		big_sort(&stack_a, &stack_b, &len);
	free_data(&stack_a, &stack_b, parsed_args);
	return (0);
}
