CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = push_swap.h
SRC = $(wildcard utils/*/*.c) main.c
OBJ = $(SRC:.c=.o)
EXEC = push_swap

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXEC)