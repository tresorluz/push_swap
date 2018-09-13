# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tluzing <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 15:57:41 by tluzing           #+#    #+#              #
#    Updated: 2018/09/04 11:20:32 by tluzing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRCS = *.c

OBJS = *.o

all: $(NAME)

$(NAME):
		@echo "\x1B[35mLibft compiled successfully\x1B[1m"
		$(CC) $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		

clean: 
	rm -rf $(OBJS)

fclean: 
		rm -rf $(OBJS)
		rm -f $(NAME)

re: fclean 

