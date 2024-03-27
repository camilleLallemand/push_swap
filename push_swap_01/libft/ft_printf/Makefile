# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 16:54:33 by calallem          #+#    #+#              #
#    Updated: 2023/12/13 06:05:30 by calallem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
SRC 	= ft_printf.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_strlen.c libft/ft_putchar_fd.c ft_all_numb.c

OBJS 	= $(SRC:.c=.o)

CFLAGS 	= -Wall -Werror -Wextra

CC	= cc

DEPS	= ft_printf.h

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
