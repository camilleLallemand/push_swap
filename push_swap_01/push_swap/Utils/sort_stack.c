#include"../push_swap.h"
static void rotate_both(t_node **a, t_node **b, t_para *para)
{
    while (*b != para->cheapest->target_node && *a != para->cheapest)
        rr(a,b,0);
    current_index(*a, para->a_size);
    current_index(*b, para->b_size);
}

static void rev_rotate_both(t_node **a, t_node **b, t_para *para)
{
    while (*b != para->cheapest->target_node && *a != para->cheapest)
        rrr(a,b,0);
    current_index(a, para->a_size);
    current_index(b, para->b_size);
}

static void move_a_to_b(t_node **a, t_node **b, t_para *para)
{
    t_node *cheapest;
    cheapest = get_cheap(*a);
    if (cheapest->above_med == 1 && cheapest->target_node->above_med == 1)
        rotate_both(a, b, para);
    else if(cheapest->above_med == 0 && cheapest->target_node->target_node == 0)
        rev_rotate_both(a, b, para);
    prep_for_push(a, cheapest, 1);
    prep_for_push(b, cheapest, 0);
    pb(a,b,0,para);
}

static void move_b_to_a(t_node **a, t_node **b,t_para *para)
{
    prep_for_push(a, *b, 1);
    pa(a,b,0,para);
}

static void min_on_top(t_node **a, t_node **b)
{
    while ((*a)->val != find_min(*a)->val)
    {
        if (find_min(*a)->above_med)
            ra(a,0);
        else
            rra(a,0);
    }
}

void sort_stack(t_node **a, t_node **b, t_para *para)
{
    if (para->a_size-- > 3 && !is_sorted(a))
        pb(a,b,0,para);
    if (para->a_size-- > 3 && !is_sorted(a))
        pb(a,b,0,para);
    while (para->a_size-- > 3 && !is_sorted(a)) {
        init_node_a(*a, *b, para);
        move_a_to_b(a, b, para);
    }
    sort_three(a);
    while (*b) {
        init_nodes_b(*a, *b, para);
        move_b_to_a(a, b, para);
    }
    current_index(*a, para->a_size);
    min_on_top(a, b);
}