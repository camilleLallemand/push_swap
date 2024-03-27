#include"push_swap.h"


void current_index(t_node *a, int size)
{
    int median;

    if (!a)
        return ;
    median = size / 2;
    while (a)
    {
        if (a->index <= median)
            a-> above_med=1;
        else
            a->above_med=0;
        a = a->next;
    }
}

static void set_target_a(t_node *a, t_node *b)
{
    t_node *cur_b;
    t_node *target;
    int    best_id;

    cur_b = NULL;
    while(a)
    {
        if (b)
        {
            best_id = b->val;
            target = b;
            cur_b = b->next;
        }
        while (cur_b)
        {
            if (cur_b->val < a->val && cur_b->val > best_id)
            {
                best_id = cur_b->val;
                target = cur_b;
            }
            cur_b = cur_b->next;
        }
        if (best_id == LONG_MIN)
            a ->target_node = find_max(b);
        else
            a ->target_node = target;
        a = a->next;
    }
}

static void cost_analysis_a(t_node *a, t_node *b, t_para *para)
{
    while(a)
    {
        a->cost = a->index;
        if (a ->above_med == 0)
            a->cost = para->a_size - a->index;
        if (a -> target_node -> above_med)
            a->cost += a->target_node->index;
        else
            a->cost += para->b_size - (a->target_node->index);
        a = a->next;
    }
}

void set_cheapest(t_node *a)
{
    int cheapest_value;
    t_node *cheapest;
    if (!a)
        return ;
    cheapest_value = 2147483647;
    while (a)
    {
        if(a->cost < cheapest_value)
        {
            cheapest_value = a->cost;
            cheapest = a;
        }
        a =a ->next;
    }
    cheapest ->cheapest = 1;
}

void init_node_a(t_node *a, t_node *b,t_para *para)
{
    current_index(a, para->a_size);
    current_index(b, para->b_size);
    set_target_a(a,b);
    cost_analysis_a(a,b,para);
}