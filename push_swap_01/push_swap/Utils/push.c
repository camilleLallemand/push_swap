#include"../push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 void ft_push(t_node **dst, t_node **src)
{
    t_node *tmp;
    if (!*src)
    {
        printf("error");
        return;
    }
    tmp = *src;
    *src = (*src)->next;
    if (*src)
        (*src)-> prev = NULL;
    if (!*dst)
    {
        *dst = tmp;
        tmp -> next = NULL;
        tmp ->prev = NULL;
    }
    else
    {
        tmp->next = *dst;
        (*dst)->prev = tmp;
        *dst = tmp;
    }
}

void pa(t_node **a, t_node **b, int prt,t_para *para)
{
    ft_push(a,b);
    para->a_size --;
    para->b_size++;
    if (prt == 0)
        printf("pa\n");
}
void pb(t_node **a, t_node **b, int prt, t_para *para)
{
    ft_push(b, a);
    para ->a_size++;
    para ->b_size--;
    if (prt == 0)
        printf("pb\n");
}

void printlinkedlist(t_node ** a, t_node **b)
{
    while((*a) || (*b))
    {
        if (!*a && *b)
        {
            printf("       B : %d pos: %d\n", (*b)->val, (*b)->index);
            (*b) = (*b)->next;
        }
        else if (*a && !*b)
        {
            printf("A : %d  pos: %d\n", (*a)->val, (*a)->index);
            (*a) = (*a)->next;
        }
        else if (*a && *b)
        {
            printf("A : %d pos: %d B : %d pos: %d\n", (*a)->val,(*a)->index, (*b)->val, (*b)->index);
            (*a)=(*a)->next;
            (*b) = (*b) -> next;
        }
    }
}
void printlist(t_node ** a)
{
    while((*a))
        {
            printf("A : %d  pos: %d\n", (*a)->val, (*a)->index);
            (*a) = (*a)->next;
        }
}