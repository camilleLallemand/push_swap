#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	long	*a;
	long	*b;
	long	*sorted;
	int		a_size;
	int		b_size;
	char	*join_args;
}	t_stacks;

// Functions from ft_ini_1.c
size_t	ft_there_is_number(char *str);
long	ft_atol(char *str);
size_t	ft_count_words(char *str, char c);
void	initialize_stacks(int argc, char **argv, t_stacks *s);
size_t	how_long(long i);

// Functions from ft_ini_2.c
size_t	ft_all_numb(char *str, t_stacks *s, size_t i);
size_t	next_value(char *str, size_t i);
void	add_value_stack(char **argv, t_stacks *s);

// Functions from ft_move.c

void	pa(t_stacks *s);
void	pb(t_stacks *s);
void	sa(t_stacks *s);
void	sb(t_stacks *s);
void	ss(t_stacks *s);

// Functions from ft_move_2.c

void	ra(t_stacks *s);
void	rb(t_stacks *s);
void	rr(t_stacks *s);
void	rra(t_stacks *s);
void	rrb(t_stacks *s);

// Functions from ft_move_3.c
void	rrr(t_stacks *s);

// Functions from ft_parcing_1.c
int		is_only_number(char *s);
int		no_space_number_2(char *s, size_t *i, int *numb, int *sign);
int		no_space_numb(char *s);
int		is_only_space(char *s);

// Functions from ft_parcing_2.c
int		ft_first_parc(char **s);
int		ft_second_parc(t_stacks *s);
int		is_int(t_stacks *s);
int		there_is_db(t_stacks *s);

// Functions from ft_tri_1.c

void	sort_three(t_stacks *s);
void	sort_three_2(t_stacks *s);
void	find_smallest(t_stacks *s, int *smallest, int *id_smallest);
void	move_smallest_to_top(t_stacks *s, int id_smallest);

//Functions from ft_tri_2.c

void	move_smallest(t_stacks *s);
void	sort_four(t_stacks *s);
void	sort_five(t_stacks *s);
int		is_sorted(t_stacks *s);
void	sort_them(t_stacks *s);

// Functions from main.c

int		fits_in_int(char *str);
int		has_duplicates(int argc, char **argv);
int		is_number(char *str);

// Functions from radix_1.c

long	*fill_index(long *index, long *tab, t_stacks *s);
long	get_abs(long num);
int		get_max_value(long *array, int size);
long	*sort_tab(long *tab, long size);
long	*tab_sort(t_stacks *s);

// Functions from radix_2.c

int		count_bits(long n);
int		ft_pow(int n, int p);
long long	long_to_bit(long n);
void	radix_sort_binary(t_stacks *s);

// Functions from radix_3.c

long	*index_tab(t_stacks *s);
void	init_radix(t_stacks *s);

#endif