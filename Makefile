# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: home <home@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 11:10:43 by ysonmez           #+#    #+#              #
#    Updated: 2021/10/14 10:45:50 by home             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		push_swap

CHECKER			=		checker

SRCS			=		srcs/push_swap.c \
						srcs/list_utils.c \
						srcs/find.c \
						srcs/parse_utils.c \
						srcs/operations.c \
						srcs/moves.c \
						srcs/utilities.c \
						srcs/calculations.c \
						srcs/sort_three_five.c \
						srcs/sort_big.c \
						srcs/get_index.c \
						srcs/markup.c \
						srcs/markup2.c \

OBJS			=		$(SRCS:.c=.o)

LIB				=		make bonus -C ./libft

SRCS_CHECKER	=		srcs_checker/get_next_line.c \
						srcs_checker/checker_parser.c \
						srcs_checker/checker.c \
						srcs_checker/checker_operations.c \
						srcs/list_utils.c \
						srcs/parse_utils.c \
						srcs/moves.c \
						srcs/utilities.c \
						srcs/get_index.c \

OBJS_CHECKER	=		$(SRCS_CHECKER:.c=.o)

CC				=		gcc

CFLAGS			=		-Wall -Wextra -Werror

RM				=		rm -f

$(NAME)			:		$(OBJS)
						$(LIB)
						$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

lib				:
						$(LIB)

checker			:		$(OBJS_CHECKER)
						$(LIB)
						$(CC) $(CFLAGS) $(OBJS_CHECKER) libft/libft.a -o $(CHECKER)


clean			:
						$(RM) $(OBJS)
						$(RM) $(OBJS_CHECKER)

fclean			:		clean
						$(RM) $(NAME)
						$(RM) $(CHECKER)
						cd ./libft && make fclean

all				:		$(NAME) $(CHECKER)

re				:		fclean all

bonus			:		all

.PHONY			:		clean fclean all re bonus
