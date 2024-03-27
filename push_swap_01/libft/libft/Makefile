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

NAME 	= libft.a
SRC 	= ft_bzero.c ft_isalnum.c  ft_isascii.c  ft_isprint.c  ft_memcmp.c  ft_memmove.c  ft_strchr.c  ft_strncmp.c  ft_tolower.c ft_atoi.c  ft_calloc.c  ft_isalpha.c  ft_isdigit.c  ft_memchr.c   ft_memcpy.c  ft_memset.c   ft_strlen.c  ft_strrchr.c  ft_toupper.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_strdup.c ft_strlcpy.c ft_striteri.c ft_strnstr.c ft_strlcat.c

OBJS 	= $(SRC:.c=.o)

CFLAGS 	= -Wall -Werror -Wextra

CC	= cc

DEPS	= libft.h

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
