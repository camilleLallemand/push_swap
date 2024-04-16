#include "../../push_swap.h"

void	sa(t_stacks *s)
{
	long	tmp;

	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *s)
{
	long	tmp;

	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stacks *s)
{
	sa(s);
	sb(s);
	write(1, "ss\n", 3);
}

void	pa(t_stacks *s)
{
	int	i;

	if (s->b_size < 1)
		return ;
	i = s->a_size++;
	while (i-- > 0)
		s->a[i + 1] = s->a[i];
	s->a[0] = s->b[0];
	i = -1;
	while (++i < s->b_size - 1)
		s->b[i] = s->b[i + 1];
	s->b_size--;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *s)
{
	int	i;

	if (s->a_size < 1)
		return ;
	i = s->b_size++;
	while (i-- > 0)
		s->b[i + 1] = s->b[i];
	s->b[0] = s->a[0];
	i = -1;
	while (++i < s->a_size - 1)
		s->a[i] = s->a[i + 1];
	s->a_size--;
	write(1, "pb\n", 3);
}
