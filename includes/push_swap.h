/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 13:14:32 by ysonmez           #+#    #+#             */
/*   Updated: 2021/10/14 11:13:00 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

/*
*	INTEGER
*		MIN : -2147483648
*		MAX : 2147483647
*/

/*
*	LIBFT
*/

# include	"../libft/libft.h"
# include	<limits.h>

/*
*	Struct to store stack A and stack B len
*/

typedef struct s_len
{
	int	a;
	int	b;
}	t_len;

/*
*	Stack creating and modifying functions
*/

t_list		*ft_create_stack_a(char **argv, int i);
void		link_tail_to_head(t_list **stack);
void		unlink_tail_to_head(t_list **stack, t_len *len);

/*
*	Parsing functions
*/

int			ft_check_duplicate(t_list *stack);
char		**ft_parser(char **argv, int i, int k);
void		get_stack_length(t_list **stack_a, t_list **stack_b, t_len *len);

/*
*	Utilities functions
*/

void		get_index(t_list **stack_a, t_len *len, int i);
int			intcmp(int n1, int n2);
bool		is_sorted(t_list *stack);
long long	ft_atoi_ll(char *str);
void		clear_stack(t_list **stack_a, t_list **stack_b, t_len *len);

/*	Algorithm */

void		small_sort(t_list **stack_a, t_list **stack_b, t_len *len);
void		big_sort(t_list **stack_a, t_list **stack_b, t_len *len);

/*	Markup functions */

int			get_markup(t_list **stack_a, t_len *len, int *arr, int *markup);
void		init_markup(int *markup);
void		fill_markup_if_better(int *arr, int *markup);
void		count_true(t_list **stack_a, t_len *len, int *arr);
void		get_specific_markup(t_list **stack_a, t_len *len, int *markup);
int			check_false_markup(t_list **stack_a, t_len *len);

/*	Calculations to push back from Stack B to Stack A */

void		calculate_rot_a(t_list **stack_a, t_len *len, int number, int *arr);
void		calculate_rot_b(t_len *len, int i, int *arr);
void		move_stacks(t_list **a, t_list **b, t_len *len, int *data);

/*	Comparisons from stack A or B */

int			bigger_than_stack(t_list **stack_a, int number);
int			smaller_than_stack(t_list **stack_a, int number);
int			find_smallest(t_list **stack);
int			find_biggest(t_list **stack);

/*
*	Operations functions && macros
*/

void		operations(t_list **stack_a, t_list **stack_b, t_len *len, int op);

int			swap(t_list **stack, t_len *len);
int			push(t_list **stack_1, t_list **stack_2);
int			rotate(t_list **stack);
int			rev_rotate(t_list **stack);

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

/*	Free data fonctions */

int			ft_error_free(t_list **stack_a, t_list **stack_b, char **arr);
void		free_data(t_list **stack_a, t_list **stack_b, char **arr);

#endif
