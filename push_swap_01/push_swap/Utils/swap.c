#include"../push_swap.h"

void ft_swap(t_node **a)
{
    t_node *tmp;
    if (!(*a) || (*a)->next == NULL)
        return ;
    tmp = (*a)->next;
    (*a)->prev = tmp;
    (*a)->next= tmp ->next;
    tmp->next = *a;
    tmp->prev = NULL;
    (*a)=tmp;
}

void sa(t_node **a, int prt)
{
    ft_swap(a);
    if(prt==0)
        printf("sa\n");
}

void sb (t_node **b, int prt)
{
    ft_swap(b);
    if(prt==0)
        printf("sb\n");
}
void ss(t_node **a, t_node **b, int prt)
{
    ft_swap(a);
    ft_swap(b);
    if(prt==0)
        printf("ss\n");
}