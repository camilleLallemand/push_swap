#include "push_swap.h"

void	free_stack(t_stacks *s)
{
	free(s->a);
	free(s->b);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc < 2)
		return (0);
	if (ft_first_parc(argv) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	initialize_stacks(argc, argv, &s);
	add_value_stack(argv, &s);
	if (ft_second_parc(&s) == -1)
	{
		free_stack(&s);
		write(2, "Error\n", 6);
		return (0);
	}
	sort_them(&s);
	free_stack(&s);
	return (0);
}
