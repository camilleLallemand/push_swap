#include "../../push_swap.h"

size_t ft_there_is_number(char *str)
{
    size_t i;
    size_t check;

    i = 0;
    check = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            check = 1;
        i++;
    }
    return (check);
}

long ft_atol(char *str)
{
    size_t i;
    long sign;
    long stock;
    size_t check;

    i = 0;
    check = 0;
    sign = 1;
    stock = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        stock = stock * 10 + str[i] - '0';
        i++;
        check++;
    }
    return (stock * sign);
}

size_t ft_count_words(char *str, char c)
{
    size_t i;
    size_t count;
    size_t check;

    i = 0;
    count = 0;
    check = 0;
    while (str[i])
    {
        if (str[i] == c)
            check = 0;
        else if (check == 0)
        {
            check = 1;
            count++;
        }
        i++;
    }
    return (count);
}

void initialize_stacks(int argc, char **argv, t_stacks *s)
{
    size_t i;
    size_t add_it;

    i = 1;
    s->b_size = 0;
    s->a_size = 0;
    while((int)i < argc)
    {
        add_it = ft_count_words(argv[i], ' ');
        if (add_it >= 1)
        {
            if (ft_there_is_number(argv[i]) != 0)
                s->a_size = add_it + s->a_size;
        }
        else
            s->a_size++;
        i++;
    }
    s->a = malloc(sizeof(long *) * (s->a_size +1));
    s->b = malloc(sizeof(long *) * (s->a_size +1));
    if (!s->a || !s->b)
        return;
}

size_t how_long(long i)
{
    size_t tt;

    tt = 0;
    if (i == 0)
        return (1);
    if (i >=0)
    {
        while(i%10 != 0)
        {
            i = i/10;
            tt++;
        }
    }
    else
    {
        tt++;
        while(i%10 != 0)
        {
            i = i/10;
            tt++;
        }
    }
    return (tt);
}

size_t ft_all_numb(char *str, t_stacks *s, size_t i)
{
    size_t k;
    size_t add_it;
    size_t j;

    k = 0;
    add_it = ft_count_words(str, ' ');
    while (add_it > k)
    {
        while (*str && *str != '-' && (*str < '0' || *str > '9'))
            str++;
        if (*str == '\0')
            break;
        if (ft_there_is_number(str) != 0)
        {
            s->a[i] = ft_atol(str);
            i++;
            j = how_long(s->a[i - 1]);
            k++;
            str = str + j;
        }
        else
            return i;
    }
    return i;
}


size_t next_value(char *str, size_t i)
{

    while (str[i] && str[i] == ' ')
        i++;
    while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
        i++;
    return i;
}

void add_value_stack(char **argv, t_stacks *s)
{
    size_t i;
    size_t j;
    size_t k;

    i = 0;
    j = 1;
    k = 0;
    while (argv[j])
    {
        while (argv[j][k] != '\0')
        {
            s->a[i++] = ft_atol(argv[j] + k);
            k = next_value(argv[j], k);
        }
        k = 0;
        j++;
    }
    s->a[i] = '\0';
}