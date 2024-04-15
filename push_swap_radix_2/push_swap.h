//
// Created by cam on 14/04/24.
//

#ifndef CHEVRE_PUSH_SWAP_H
#define CHEVRE_PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stacks
{
    long		*a;
    long		*b;
    long        *sorted;
    int		a_size;
    int		b_size;
    char	*join_args;
}			t_stacks;

///////FONCTION DE PARCING////

// Functions from ft_parcing_1.c
int is_only_number(char *s);
int is_only_space(char *s);
int is_int(t_stacks *s);
int there_is_db(t_stacks *s);
int ft_first_parc(char **s);
int ft_second_parc(t_stacks *s);




///CREATION DE LA STRUCTURE DE LA PILE////

// Functions from ft_ini_1.c
size_t ft_there_is_number(char *str);
long ft_atol(char *str);
size_t ft_count_words(char *str, char c);
void initialize_stacks(int argc, char **argv, t_stacks *s);
size_t how_long(long i);
size_t ft_all_numb(char *str, t_stacks *s, size_t i);
void add_value_stack(char **argv, t_stacks *s);




/// fonction de deplacement////

// Functions from ft_move.c
void sa(t_stacks *s);
void sb(t_stacks *s);
void ss(t_stacks *s);
void pa(t_stacks *s);
void pb(t_stacks *s);

// Functions from ft_move_2.c
void ra(t_stacks *s);
void rb(t_stacks *s);
void rr(t_stacks *s);
void rra(t_stacks *s);
void rrb(t_stacks *s);

// Functions from ft_move_3.c
void rrr(t_stacks *s);





/// Fonction de tri///

// Functions from ft_tri_1.c
void sort_three(t_stacks *s);
void move_small_five(t_stacks *s);
void move_smallest(t_stacks *s);
void sort_four(t_stacks *s);
void sort_five(t_stacks *s);


// Functions from ft_tri_2.c
int get_max_value(long *array, int size);
void radix_sort(t_stacks *s);
void sort_them(t_stacks *s);
int is_sorted(t_stacks *s);


// Functions from radix_1.c
void init_radix(t_stacks *s);

////operation du main////


// Functions from main.c
int is_number(char *str);
int fits_in_int(char *str);
int has_duplicates(int argc, char **argv);



#endif //CHEVRE_PUSH_SWAP_H
