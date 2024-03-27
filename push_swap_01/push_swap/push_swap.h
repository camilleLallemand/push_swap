//
// Created by lalle on 09/02/2024.
//

#ifndef PUSH_SWAP_01_PUSH_SWAP_H
#define PUSH_SWAP_01_PUSH_SWAP_H

#include<unistd.h>
#include"../libft/libft/libft.h"
#include <stdio.h>

typedef struct s_node
{
    int val;
    int index;
    int above_med;
    int cost;
    int cheapest;
    struct s_node *next;
    struct s_node *prev;
    struct s_node *target_node;
}   t_node;
typedef struct s_para
{
    int a_size;
    int b_size;
    t_node *cheapest;
} t_para;

void current_index(t_node *a, int size);
t_node *find_max(t_node *a);
void pa(t_node **a, t_node **b, int prt, t_para *para);
void pb(t_node **a, t_node **b, int prt, t_para *para);
void sa(t_node **a, int prt);
void sb(t_node **b, int prt);
void ss(t_node **a, t_node **b, int prt);
void ra(t_node **a, int prt);
void rb(t_node **b, int prt);
void rr(t_node **a, t_node **b, int prt);
void rra(t_node **a, int prt);
void rrb(t_node **b, int prt);
void rrr(t_node **a, t_node **b, int prt);
void sort_three(t_node **a);
int check_error(char **s);
t_node *find_min(t_node *a);
t_node *get_cheap(t_node *a);
void prep_for_push(t_node **a, t_node *top_node, int wish_one);
void init_node_a(t_node *a, t_node *b,t_para *para);
void init_nodes_b(t_node *a, t_node *b, t_para *para);

void printlist(t_node ** a);
void sort_stack(t_node **a, t_node **b, t_para *para);
int ft_ct_wrd(char *s);
void fill_node(t_node **head, char **s, t_para size);
int is_sorted(t_node **a);
void printlinkedlist(t_node ** a, t_node **b);
void fillLinkedList(t_node **head, char **values, int size) ;
#endif //PUSH_SWAP_01_PUSH_SWAP_H
