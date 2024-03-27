# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 16:54:33 by calallem          #+#    #+#              #
#    Updated: 2023/11/20 19:10:27 by calallem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap.a
SRC 	= a_to_b.c check_error.c ft_utils.c init_b_to_a.c init_pile.c

OBJS 	= $(SRC:.c=.o)

CFLAGS 	= -Wall -Werror -Wextra

CC	= cc

DEPS	= push_swap.h

all:	$(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:	%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(DEPS) -c $< -o $@

clean:
	rm -rf $(OBJS) 

fclean:	clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
