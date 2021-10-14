/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:57:07 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/12 19:36:06 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*	Check if the operation is Swap */

static int	check_s(char *str)
{
	if (str[0] == 's')
	{
		if (str[1] == 'a' && str[2] == '\0')
			return (1);
		else if (str[1] == 'b' && str[2] == '\0')
			return (1);
		else if (str[1] == 's' && str[2] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}

/*	Check if the operation is Push */

static int	check_p(char *str)
{
	if (str[0] == 'p')
	{
		if (str[1] == 'a' && str[2] == '\0')
			return (1);
		else if (str[1] == 'b' && str[2] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}

/*	Check if the operation is Rotate */

static int	check_r(char *str)
{
	if (str[0] == 'r' && str[2] == '\0')
	{
		if (str[1] == 'a' && str[2] == '\0')
			return (1);
		else if (str[1] == 'b' && str[2] == '\0')
			return (1);
		else if (str[1] == 'r' && str[2] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}

/*	Check if the operation is Reverse Rotate */

static int	check_rr(char *str)
{
	if (str[0] == 'r' && str[2] != '\0')
	{
		if (str[1] == 'r' && str[2] == 'a')
			return (1);
		else if (str[1] == 'r' && str[2] == 'b')
			return (1);
		else if (str[1] == 'r' && str[2] == 'r')
			return (1);
		else
			return (0);
	}
	return (0);
}

/*	Check if the operation the output of push swap or the input of the user
*	are well formatted and the operation exist
*/

int	verify_inputs(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (check_s(arr[i]))
			i++;
		else if (check_p(arr[i]))
			i++;
		else if (check_r(arr[i]))
			i++;
		else if (check_rr(arr[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
