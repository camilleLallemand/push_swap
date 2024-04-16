#include "../../push_swap.h"

void	sort_three_2(t_stacks *s)
{
	{
		if (s->a[1] < s->a[2])
		{
			ra(s);
		}
		else
		{
			sa(s);
			rra(s);
		}
	}
}

void	sort_three(t_stacks *s)
{
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2])
	{
		if (s->a[1] > s->a[2])
		{
			ra(s);
			sa(s);
			rra(s);
		}
	}
	else if ((s->a[0] > s->a[1] || s->a[0] > s->a[2])
		&& (s->a[1] > s->a[0] || s->a[2] > s->a[0]))
	{
		if (s->a[1] < s->a[2])
			sa(s);
		else
			rra(s);
	}
	else
		(sort_three_2(s));
}

void	find_smallest(t_stacks *s, int *smallest, int *id_smallest)
{
	int	i;

	i = 1;
	*smallest = s->a[0];
	*id_smallest = 0;
	while (i < s->a_size)
	{
		if (s->a[i] < *smallest)
		{
			*smallest = s->a[i];
			*id_smallest = i;
		}
		i++;
	}
}

void	move_smallest_to_top(t_stacks *s, int id_smallest)
{
	if (id_smallest > s->a_size / 2)
	{
		while (id_smallest != s->a_size)
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
