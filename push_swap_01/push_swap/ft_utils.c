#include "push_swap.h"

t_node *find_max(t_node *a)
{
    int max;
    t_node *max_node;

    if (!a)
        return NULL;
    max = a->val;
    max_node = a;
    a = a->next;
    while (a)
    {
        if(a->val > max)
        {
            max = a->val;
            max_node = a;
        }
        a = a ->next;
    }
    return (max_node);
}

t_node *find_min(t_node *a)
{
    int min;
    t_node *min_node;
    if (!a)
        return NULL;
    min = 2147483647;
    while (a)
    {
        if (a->val < min)
        {
            min = a->val;
            min_node = a;
        }
        a = a->next;
    }
    return (min_node);
}

t_node *get_cheap(t_node *a)
{
    if (!a)
        return NULL;
    while(a)
    {
        if (a->cheapest == 1)
            return a;
        a = a->next;
    }
    return a;
}

void prep_for_push(t_node **a, t_node *top_node, int wish_one)
{
    while (*a != top_node)
    {
        if (wish_one == 1)
        {
            if (top_node->above_med == 1)
                ra(a, 0);
            else
                rra(a, 0);
        }
        else
        {
            if (top_node->above_med == 1)

                rb(a,0);
            else
                rrb(a,0);
        }
    }
}