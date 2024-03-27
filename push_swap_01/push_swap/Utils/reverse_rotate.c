#include"../push_swap.h"

void ft_reverse_rotate(t_node **a)
{
    t_node *tmp;
    t_node *stock;

    tmp = (*a);
    stock = (*a);
    if (!(*a) || (*a)->next == NULL)
        return;
    while(tmp->next != NULL)
        tmp=tmp->next;

    (*a)->prev = tmp;
    tmp->next = *a;
    tmp->prev->next=NULL;
    tmp->prev = NULL;
    (*a)=tmp;
}

void rra(t_node **a, int prt)
{
    if(prt==0)
        printf("rra\n");
    ft_reverse_rotate(a);
}

void rrb(t_node **b, int prt)
{
    if(prt==0)
        printf("rrb\n");
    ft_reverse_rotate(b);
}

void rrr(t_node **a, t_node **b , int prt)
{
    if (prt ==0)
        printf("rrr\n");
    ft_reverse_rotate(a);
    ft_reverse_rotate(b);
}
