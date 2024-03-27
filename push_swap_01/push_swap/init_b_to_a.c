#include "push_swap.h"
static void set_target_b(t_node *a, t_node *b)
{
    t_node *curr_a;
    t_node *target;
    long best_index;

    while(b)
    {
        best_index = 2147483647;
        curr_a = a;

        while (curr_a)
        {
            if (curr_a ->val > b->val && curr_a->val < best_index)
            {
                best_index = curr_a->val;
                target = curr_a;
            }
            curr_a = curr_a->next;
        }
        if(best_index == 2147483647)
            b->target_node = find_min(a);
        else
            b->target_node = target;
        b =b ->next;
    }
}

void init_nodes_b(t_node *a, t_node *b, t_para *para)
{
    current_index(a, para->a_size);
    current_index(b, para->b_size);
    set_target_b(a,b);
}