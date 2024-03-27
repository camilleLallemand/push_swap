#include "push_swap.h"
static size_t	count_word(char const *s1, char c)
{
    size_t	i;
    int		res;
    int		count;

    count = 0;
    i = 0;
    res = 1;
    while (s1[i])
    {
        if (s1[i] == c && res == 0)
            res = 1;
        if (s1[i] != c && res == 1)
        {
            res = 0;
            count ++;
        }
        i++;
    }
    return (count);
}

static size_t	is_word(char const *s1, char c, size_t i, int role)
{
    if (role == 1)
    {
        while (s1[i] != c && s1[i])
            i++;
        return (i);
    }
    else
    {
        while (s1[i] == c)
            i++;
        return (i);
    }
}

static int	free_tab(char **tab, int i)
{
    if (!tab[i])
    {
        while (i >= 0)
        {
            free(tab[i]);
            i--;
        }
        free(tab);
        return (0);
    }
    return (1);
}

static char	*create_word(char const *s1, int a, int b)
{
    size_t	i;
    char	*ns;

    i = 0;
    ns = malloc(sizeof(char) * (b - a + 1));
    if (!ns)
        return ((void *)0);
    while (a < b)
    {
        ns[i] = s1[a];
        i++;
        a++;
    }
    ns[i] = '\0';
    return (ns);
}

char	**ft_split(char const *s, char c)
{
    char		**tab;
    size_t		i;
    size_t		pos;
    size_t		wordnbr;

    i = 0;
    pos = 0;
    if (!s)
        return NULL;
    wordnbr = count_word(s, c);
    tab = malloc(sizeof (char *) * (wordnbr + 1));
    if (!tab)
        return ((void *)0);
    while (i < wordnbr)
    {
        pos = is_word(s, c, pos, 0);
        tab[i] = create_word(s, pos, is_word(s, c, pos, 1));
        pos = is_word(s, c, pos, 1);
        if (free_tab(tab, i) == 0)
            return ((void *)0);
        i++;
    }
    tab[i] = ((void *)0);
    return (tab);
}

void fill_node(t_node **head, char **s, t_para para)
{
    t_node *new;
    t_node *prev;
    int i;

    i = 0;
    (prev) = NULL;
    (new) = NULL;
    while( i < para.a_size)
    {
        new = malloc(sizeof(t_node));
        if (!new)
            return;
        new->val = ft_atoi(s[i]);
        new->index = i;
        new->next = NULL;

        if (prev != NULL) {
            prev->next = new;
            new->prev = prev;
        } else {
            new->prev = NULL;
            *head = new;
        }
        prev = new;
        i++;
    }
}

int ft_howlong(char **a)
{
    int i;
    i = 0;
    while (a[i])
        i++;
    return i;
}

int main(void)
{
    t_node *a;
    t_node *b;
    t_para *para;

    int argc = 5;
    char *argv[]= {"0","-1","27","3","-4548",};
    a = NULL;
    b = NULL;
    //if (argc <2 ||(argc == 2 && !argv[1][0]))
    //    return 1;
    //if (argc == 2)
    //    argv = ft_split(argv[1], 32);
    para= malloc(sizeof(t_para));
    if (!para)
        return(0);
    //para->a_size = ft_howlong(argv);
    para->a_size = 5;

    //if (check_error(argv + 1) == -1) //dabord tu fais ton split, une fois que tu as ton tab, tu check les values donc double valeur, nbr, overflow
     //   return -1;
    fill_node(&a, argv, *para);
    if (!is_sorted(&a)) //Check if the stack is not sorted
    {
        if (para->a_size == 2) //If not, and there are two numbers, swap the first two nodes
            sa(&a, 0);
        else if (para->a_size == 3) //If not, and there are three numbers, call the sort three algorithm
            sort_three(&a);
        else
            sort_stack(&a, &b,para); //If not, and there are more than three numbers, call the sort stacks algorithm
    }
    printlist(&a);
    return (0);
}