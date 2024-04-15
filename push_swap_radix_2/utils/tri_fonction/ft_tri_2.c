#include "../../push_swap.h"


long get_abs(long num)
{
    return (num < 0) ? -num : num;
}

int get_max_value(long *array, int size)
{
    long max_value = get_abs(array[0]);
    int i;

    for (i = 1; i < size; i++)
    {
        if (get_abs(array[i]) > max_value)
        {
            max_value = get_abs(array[i]);
        }
    }

    return max_value;
}

int is_sorted_desc(t_stacks *s)
{
    int i;

    i = 0;
    while (i < s->a_size - 1)
    {
        if (s->a[i] < s->a[i + 1])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void radix_sort(t_stacks *s)
{
    int max_value = get_max_value(s->a, s->a_size);
    int exp;

    for (exp = 1; max_value / exp > 0; exp *= 10) {
        int original_a_size = s->a_size;
        int i;

        for (i = 0; i < original_a_size; i++) {
            if ((s->a[0] / exp) % 10 == 0) {
                printf("pb\n");
                pb(s);
            } else {
                printf("ra\n");
                ra(s);
            }
        }

        while (s->b_size > 0) {
            printf("pa\n");
            pa(s);
        }
    }

    // Check if the stack is sorted in descending order
    if (is_sorted_desc(s)) {
        // If so, reverse the stack
        while (s->a_size > 1) {
            printf("rra\n");
            rra(s);
        }
    }
}


int is_sorted(t_stacks *s)
{
    int i;

    i = 0;
    while (i < s->a_size - 1)
    {
        if (s->a[i] > s->a[i + 1])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void sort_them(t_stacks *s)
{
    if (is_sorted(s) == 1)
        return;
    if (s->a_size == 1)
        return;
    if (s->a_size == 2)
        if (s->a[0] > s->a[1])
            sa(s);
    if (s->a_size == 3)
        sort_three(s);
    else if (s->a_size == 4)
        sort_four(s);
    else if (s->a_size == 5)
        sort_five(s);
    else if (s->a_size > 5)
        init_radix(s);
}
