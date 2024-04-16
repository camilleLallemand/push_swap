#include "../../push_swap.h"

void	ra(t_stacks *s)
{
	long	tmp;
	int		i;

	i = 0;
	tmp = s->a[0];
	while (i < s->a_size)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->a_size - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stacks *s)
{
	long	tmp;
	int		i;

	i = 0;
	tmp = s->b[0];
	while (i < s->b_size)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[s->b_size - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stacks *s)
{
	ra(s);
	rb(s);
	write(1, "rr\n", 3);
}

void	rra(t_stacks *s)
{
	long	tmp;
	size_t	i;

	i = s->a_size - 1;
	tmp = s->a[s->a_size - 1];
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *s)
{
	long	tmp;
	size_t	i;

	i = s->b_size - 1;
	tmp = s->b[s->b_size - 1];
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = tmp;
	write(1, "rrb\n", 4);
}
