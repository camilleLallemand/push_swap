#include "../../push_swap.h"

long	get_abs(long num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	get_max_value(long *array, int size)
{
	long	max_value;
	int		i;

	max_value = get_abs(array[0]);
	i = 1;
	while (i < size)
	{
		if (get_abs(array[i]) > max_value)
			max_value = get_abs(array[i]);
		i++;
	}
	return (max_value);
}

long	*sort_tab(long *tab, long size)
{
	long	i;
	long	temp;

	i = 0;
	while (i < size - 1)
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

long	*tab_sort(t_stacks *s)
{
	long	i;
	long	*tab;

	i = 0;
	tab = malloc(sizeof(long) * (s->a_size + 1));
	if (tab == NULL)
		return (NULL);
	while (i < s->a_size)
	{
		tab[i] = s->a[i];
		i++;
	}
	return (sort_tab(tab, s->a_size));
}

long	*fill_index(long *index, long *tab, t_stacks *s)
{
	long	i;
	long	j;

	i = 0;
	j = 0;
	while (j < s->a_size && i < s->a_size)
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
