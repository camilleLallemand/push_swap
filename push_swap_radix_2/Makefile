CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = push_swap.h
SRC = utils/init_fonction/ft_ini_1.c utils/move_fonction/ft_move.c  utils/move_fonction/ft_move_2.c utils/move_fonction/ft_move_3.c utils/tri_fonction/ft_tri_1.c utils/tri_fonction/ft_tri_2.c utils/parcing_function/ft_parcing_1.c utils/tri_fonction/radix_1.c main.c
OBJ = $(SRC:.c=.o)
EXEC = push_swap

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXEC)