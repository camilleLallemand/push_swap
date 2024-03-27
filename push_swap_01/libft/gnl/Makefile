# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 16:54:33 by calallem          #+#    #+#              #
#    Updated: 2024/01/08 23:03:57 by calallem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= get_next_line.a
SRC 	=get_next_line.c get_next_line_utils.c

OBJS 	= $(SRC:.c=.o)

CFLAGS 	= -Wall -Werror -Wextra

CC	= cc

DEPS	= get_next_line.h

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
