#include "../../push_swap.h"

int is_only_number(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if ((s[i] < '0' || s[i] > '9') && (s[i] != '-' && s[i] != ' '))
            return (-1);
        i++;
    }
    return (1);
}

int no_space_numb(char *s)
{
    int i;
    int numb;
    int sign;

    i = 0;
    numb = 0;
    sign = 0;
    while (s[i])
    {
        if (sign !=0 && (s[i] < '0' || s[i] > '9'))
            return -1;
        if (s[i] >= '0' && s[i] <= '9') {
            numb++;
            sign = 0;
        }
        if ((s[i] == '-' || s[i] == '+') && numb !=0)
            return -1;
        if (s[i] == ' ' && numb != 0)
            numb = 0;
        if (s[i] == '-' || s[i] == '+')
            sign++;
        i++;
    }
    if (sign != 0)
        return -1;
    return 1;
}
int is_only_space(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] != ' ')
            return (1);
        i++;
    }
    return (-1);
}

int is_int(t_stacks *s) {
    int i;

    i = 0;
    while (i < s->a_size) {
        if (s->a[i] > 2147483647 || s->a[i] < -2147483648)
            return (-1);
        i++;
    }
    return (1);
}

int there_is_db(t_stacks *s) {
    int i;
    int j;

    i = 0;
    j = 1;
    while (i < s->a_size) {
        while (j < s->a_size) {
            if (s->a[i] == s->a[j])
            {
                printf("%ld\n", s->a[i]);
                printf("%d, %d\n", i, j);
                return (-1);
            }
            j++;
        }
        i++;
        j = i + 1;
    }
    return (1);
}

int ft_first_parc(char **s)
{
    int i;

    i = 1;
    while (s[i])
    {
        if (is_only_number(s[i]) == -1)
            return (-1);
        if (is_only_space(s[i]) == -1)
            return (-1);
        if (no_space_numb(s[i]) == -1)
            return (-1);
        i++;
    }
    return (1);
}



int ft_second_parc(t_stacks *s)
{
    if (is_int(s) == -1)
        return (-1);
    if (there_is_db(s) == -1)
        return (-1);
    return (1);
}