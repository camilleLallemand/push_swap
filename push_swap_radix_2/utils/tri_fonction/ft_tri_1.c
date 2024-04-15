#include "../../push_swap.h"

void sort_three(t_stacks *s)
{
    if (s->a[0] < s->a[1] && s->a[0] < s->a[2])
    {
        if (s->a[1] > s->a[2]) {
            ra(s);
            sa(s);
            rra(s);
        }
    }
    else if ((s->a[0] > s->a[1] || s->a[0] > s->a[2] )&& (s->a[1] > s->a[0] || s->a[2] > s->a[0]))
    {
        if (s->a[1] < s->a[2])
            sa(s);
        else
            rra(s);
    }
    else
    {
        if (s->a[1] < s->a[2]) {
            ra(s);
        }
        else {
            sa(s);
            rra(s);
        }
    }
}


void move_small_five(t_stacks *s)
{
    int i;
    int stock_small;
    int stock_vr_small;
    long small;
    long vr_small;

    i = 2;
    stock_small = 0;
    stock_vr_small = 1;
    small = s->a[0];
    vr_small = s->a[1];
    while (s->a_size > i)
    {
        if (s->a[i] < small)
        {
            vr_small = small;
            stock_vr_small = stock_small;
            small = s->a[i];
            stock_small = i;
        }
        else if (s->a[i] < vr_small && s->a[i] != small)
        {
            vr_small = s->a[i];
            stock_vr_small = i;
        }
        i++;
    }
    //printf("small = %ld, vr_small = %ld\n", small, vr_small);
    i = 0;
    while( 5 - i != stock_small && i != stock_small && 5 - i != stock_vr_small && i != stock_vr_small)
        i++;

    if (5 - i == stock_vr_small  || 5 - i == stock_small)
    {
        while ( i !=0)
        {
            rra(s);
            i--;
        }
        if (s->a[0] == vr_small)
            i = stock_vr_small;
        else
            i = stock_small;
        pb(s);
        while(s->a[0] != vr_small && s->a[0] != small)
            rra(s);
        pb(s);
    }
    else
    {
        while ( i !=0)
        {
            ra(s);
            i--;
        }
        pb(s);
        while(s->a[0] != vr_small && s->a[0] != small)
            ra(s);
        pb(s);
    }
}

void move_smallest(t_stacks *s)
{
    int i;
    int smallest;
    int id_smallest;

    i = 1;
    smallest = s->a[0];
    id_smallest = 0;
    while (i < s->a_size)
    {
        if (s->a[i] < smallest)
        {
            smallest = s->a[i];
            id_smallest = i;
        }
        i++;
    }
    if (id_smallest > s->a_size / 2)
    { while (id_smallest != s->a_size)
        {
            rra(s);
            id_smallest++;
        }
    }
    else
    {
        while (id_smallest != 0)
        {
            ra(s);
            id_smallest--;
        }
    }
}


void sort_four(t_stacks *s)
{
    move_smallest(s);
    pb(s);
    sort_three(s);
    pa(s);
}

void sort_five(t_stacks *s)
{
    //move_small_five(s);
    move_smallest(s);
    pb(s);
    move_smallest(s);
    pb(s);
    sort_three(s);
    if (s->b[0] < s->b[1])
        sb(s);
    pa(s);
    pa(s);
}