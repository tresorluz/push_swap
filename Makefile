# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tluzing <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 17:19:37 by tluzing           #+#    #+#              #
#    Updated: 2018/09/08 10:18:14 by tluzing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/debug.c  srcs/valid_input.c srcs/init_struct.c srcs/swap_cmd.c srcs/push_cmd.c\
		srcs/rot_cmd.c srcs/rrot_cmd.c srcs/valid_ops.c srcs/check_order.c srcs/helpers.c\
		srcs/initstructhelp.c srcs/ret_process.c srcs/sort_algo.c srcs/struct_b_moves.c srcs/movement.c\
		srcs/prepoprot.c srcs/ret_process2.c

OBJS =	debug.o  valid_input.o init_struct.o swap_cmd.o push_cmd.o rot_cmd.o rrot_cmd.o valid_ops.o\
		check_order.o helpers.o initstructhelp.o ret_process.o sort_algo.o struct_b_moves.o movement.o\
		prepoprot.o ret_process2.o

HEADERS = -I libft/includes -I includes/

LIB = libft/libft.a -lncurses

$(NAME1) :
	@make fclean -C libft/
	@make -C libft/
	@make clean -C libft/
	@gcc $(CFLAGS) -c $(SRCS) srcs/checker.c $(HEADERS)
	@gcc $(CFLAGS) $(OBJS) checker.o -o $(NAME1) $(LIB)
	@make clean
	@echo "\x1B[32mChecker compiled successfully\x1B[1m"

$(NAME2) :
	@make fclean -C libft/
	@make -C libft/
	@make clean -C libft/
	@gcc $(CFLAGS) -c $(SRCS) srcs/push_swap.c $(HEADERS)
	@gcc $(CFLAGS) $(OBJS) push_swap.o -o $(NAME2) $(LIB)
	@make clean
	@echo "\x1B[33mPush_swap compiled successfully\x1B[0m"

all : $(NAME1) $(NAME2)

clean :
	@rm -rf $(OBJS) checker.o push_swap.o

fclean : clean
	@make fclean -C libft/
	@rm -rf $(NAME1) $(NAME2)

re : fclean all
