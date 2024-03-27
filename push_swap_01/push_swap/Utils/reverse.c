#include"../push_swap.h"

void ft_reverse(t_node **a)
{
    if (!(*a) || ((*a)->next == NULL))
        return ;
    t_node *tmp;
    t_node *stock;

    stock = (*a)->next;
    tmp = (*a);
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next=(*a);
    (*a)->next = NULL;
    (*a)->prev= tmp;
    stock->prev = NULL;
    (*a) = stock;
}

void ra(t_node **a, int prt)
{
    ft_reverse(a);
    if(prt ==0)
        printf("ra\n");
}

void rb(t_node **b, int prt)
{
    ft_reverse(b);
    if(prt == 0)
        printf("rb\n");
}
void rr(t_node **a, t_node **b, int prt)
{
    ft_reverse(a);
    ft_reverse(b);
    if (prt == 0)
        printf("rr\n");
}