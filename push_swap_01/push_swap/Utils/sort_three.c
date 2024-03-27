#include"../push_swap.h"

void sort_three(t_node **a)
{
    t_node *tmp;
    tmp = (*a);
    if(tmp->val < tmp->next->val)
        tmp=tmp->next;
    if (tmp->val < (*a)->next->next->val)
        tmp = (*a)->next->next;
    if(tmp == (*a))
        ra(a,0);
    else if (tmp==(*a)->next)
        rra(a,0);
    if ((*a)->val > (*a)->next->val)
        sa(a,0);
}

int is_sorted(t_node **a)
{
    while((*a)->next != NULL && (*a)->val < (*a)->next->val) {
        write(1, "c", 1);
        (*a) = (*a)->next;
    }
    if ((*a)->next == NULL)
        return 1;
    return 0;
}