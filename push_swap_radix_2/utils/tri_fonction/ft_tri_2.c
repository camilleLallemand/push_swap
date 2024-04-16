#include "../../push_swap.h"

void	move_smallest(t_stacks *s)
{
	int	smallest;
	int	id_smallest;

	find_smallest(s, &smallest, &id_smallest);
	move_smallest_to_top(s, id_smallest);
}

void	sort_four(t_stacks *s)
{
	move_smallest(s);
	pb(s);
	sort_three(s);
	pa(s);
}

void	sort_five(t_stacks *s)
{
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

int	is_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_them(t_stacks *s)
{
	if (is_sorted(s) == 1)
		return ;
	if (s->a_size == 1)
		return ;
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
