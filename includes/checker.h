/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:17:41 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/14 10:47:52 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include "push_swap.h"

/* -------- GET NEXT LINE -------- */

typedef struct s_gnl
{
	char		*buff;
	char		*newline;
	int			r;
	int			i;
}	t_gnl;

char	*get_next_line(int fd);

# define BUFFER_SIZE	1

/*	Verifying push_swap outputs reads by the checker
	and verify the algorithm ny executing the operations
*/

void	checker(t_list **stack_a, t_list **stack_b, t_len *len, int op);
int		verify_inputs(char **arr);

#endif
