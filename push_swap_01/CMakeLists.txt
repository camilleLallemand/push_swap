cmake_minimum_required(VERSION 3.26)
project(push_swap_01 C)

set(CMAKE_C_STANDARD 11)

add_executable(push_swap_01 main.c
        push_swap/push_swap.h
        libft/libft/Makefile
        libft/libft/ft_substr.c
        libft/libft/ft_putendl_fd.c
        libft/libft/ft_strlen.c
        push_swap/Utils/push.c
        push_swap/Utils/swap.c
        push_swap/Utils/reverse.c
        push_swap/Utils/reverse_rotate.c
        push_swap/Utils/sort_three.c
        push_swap/init_pile.c
        libft/libft/ft_atoi.c
        push_swap/check_error.c
        push_swap/a_to_b.c
        push_swap/ft_utils.c
        push_swap/init_b_to_a.c
        push_swap/Utils/sort_stack.c
)
