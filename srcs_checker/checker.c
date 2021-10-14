/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:17:43 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/13 20:25:07 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*	Function to read on STDIN (user's inputs or results of push swap)
*	Read everything and store the data in an array
*/

static char	**read_push_swap(void)
{
	char	*buff;
	char	*str;
	char	*tmp;
	char	**arr;

	buff = get_next_line(0);
	str = ft_strdup("");
	while (buff != NULL)
	{
		if (ft_strchr(buff, '\n') == NULL)
			return (NULL);
		tmp = str;
		str = ft_strjoin(tmp, buff);
		ft_memfree((void *)buff);
		ft_memfree((void *)tmp);
		buff = get_next_line(0);
	}
	arr = ft_split(str, '\n');
	ft_memfree((void *)str);
	return (arr);
}

/*	Executing the read algo on checker's stacks */

static void	sort(t_list **stack_a, t_list **stack_b, t_len *len, char *str)
{
	if (str[0] == 's' && str[1] == 'a')
		checker(stack_a, stack_b, len, SA);
	else if (str[0] == 's' && str[1] == 'b')
		checker(stack_a, stack_b, len, SB);
	else if (str[0] == 's' && str[1] == 's')
		checker(stack_a, stack_b, len, SS);
	else if (str[0] == 'p' && str[1] == 'a')
		checker(stack_a, stack_b, len, PA);
	else if (str[0] == 'p' && str[1] == 'b')
		checker(stack_a, stack_b, len, PB);
	else if (str[0] == 'r' && str[1] == 'a')
		checker(stack_a, stack_b, len, RA);
	else if (str[0] == 'r' && str[1] == 'b')
		checker(stack_a, stack_b, len, RB);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		checker(stack_a, stack_b, len, RR);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		checker(stack_a, stack_b, len, RRA);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		checker(stack_a, stack_b, len, RRB);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		checker(stack_a, stack_b, len, RRR);
}

/*	Create two stack, parse and check inputs, fill stack A with parameters
*	Execute the algorithm read by the checker on STDIN
*	Verify that the stack is sorted
*/

static int	tester(char **arr, char **argv, int i)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_len	len;
	char	**parsed_args;

	parsed_args = ft_parser(argv, 1, 0);
	stack_a = ft_create_stack_a(parsed_args, 0);
	stack_b = NULL;
	if (stack_a == NULL || !ft_check_duplicate(stack_a))
	{
		free_data(&stack_a, &stack_b, parsed_args);
		return (0);
	}
	get_stack_length(&stack_a, &stack_b, &len);
	while (arr[i] != NULL)
	{
		sort(&stack_a, &stack_b, &len, arr[i]);
		i++;
	}
	if (is_sorted(stack_a) == true && len.b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_data(&stack_a, &stack_b, parsed_args);
	return (1);
}

/*	Read everything in STDIN (0) and store the outputs of the algorithm
*	Verify if the operations exist int he current list and if there is a \n
*		for each opertion
*	Create stack A, B, do the stored algorithm to the parameters
*	Check if this is sorted
*/

int	main(int argc, char **argv)
{
	char	**arr;

	if (argc < 2)
		return (-1);
	arr = read_push_swap();
	if (arr == NULL)
		ft_putstr_fd("Error\n", 1);
	if (!(verify_inputs(arr)))
		ft_putstr_fd("Error\n", 1);
	if (!(tester(arr, argv, 0)))
		ft_putstr_fd("Error\n", 1);
	ft_memfreeall((void **)arr);
	return (0);
}
