#include "../../push_swap.h"


long *tab_sort(t_stacks *s)
{
    long i;
    long *tab;
    long temp;

    i = 0;
    tab = malloc(sizeof(long) * (s->a_size + 1));
    if (tab == NULL)
        return NULL;
    while(i < s->a_size)
    {
        tab[i] = s->a[i];
        i++;
    }
    i = 0;
    while(i < s->a_size - 1)
    {
        if (tab[i] > tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = 0;
        }
        else
            i++;
    }
    return (tab);
}



long *index_tab(t_stacks *s)
{
    long i;
    long j;
    long *tab;
    long *index;

    tab = tab_sort(s);
    if (tab == NULL)
        return NULL;
    i = 0;
    j = 0;
    index = malloc(sizeof(long) * (s->a_size+1));
    if (index == NULL)
        return NULL;
    while(j < s->a_size && i < s->a_size)
    {
        if (s->a[i] == tab[j])
        {
            index[i] = j;
            i++;
            j = 0;
        }
        else
            j++;
    }

    free(tab);
    free(s->a);
    return (index);
}

void print_stack(t_stacks *s)
{
    long i;

    i = 0;
    write(1, "stack a\n", 8);
    while(i < s->a_size)
    {
        printf("%ld\n", s->a[i]);
        i++;
    }
    write(1, "stack b\n", 8);
    i = 0;
    while(i < s->b_size)
    {
        printf("%ld\n", s->b[i]);
        i++;
    }
}

int ft_pow(int n, int p)
{
    int i;
    int res;

    i = 0;
    res = 1;
    while (i < p)
    {
        res = res * n;
        i++;
    }
    return res;
}

long long long_to_bit(long n)
{
    long long bit = 0;
    long i = 0;

    while (n > 0)
    {
        bit = bit + (n % 2) * ft_pow(10, i);
        n = n / 2;
        i++;
    }
    return bit;
}

int count_bits(long n) {
    int count = 0;
    while (n) {
        count++;
        n >>= 1;
    }
    return count;
}
void radix_sort_binary(t_stacks *s) {
    long max_value = get_max_value(s->a, s->a_size);
    int max_bits = count_bits(max_value);
    int i;
    int size;

    i = 0;
    while(i < max_bits) {
        size = s->a_size;
        while (size--) {
            if (((s->a[0] >> i) & 1) == 0)
                pb(s);
            else
                ra(s);
        }
        i++;

        while (s->b_size > 0) {
            pa(s);
        }
    }
}


void init_radix(t_stacks *s) {

    s->a = index_tab(s);
    if (s->a == NULL) {
        write(2, "Error\n", 6);
        return;
    }
    //while(is_sorted(s) == 0)
    radix_sort_binary(s);
    /*
    int i = 0;
    while (i < s->a_size) {
        printf("%ld\n", s->a[i]);
        i++;
    }
     */

}