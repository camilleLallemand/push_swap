#include "../../push_swap.h"

long	*index_tab(t_stacks *s)
{
	long	*tab;
	long	*index;

	tab = tab_sort(s);
	if (tab == NULL)
		return (NULL);
	index = malloc(sizeof(long) * (s->a_size + 1));
	if (index == NULL)
		return (NULL);
	return (fill_index(index, tab, s));
}

void	init_radix(t_stacks *s)
{
	s->a = index_tab(s);
	if (s->a == NULL)
	{
		write(2, "Error\n", 6);
		return ;
	}
	radix_sort_binary(s);
}
