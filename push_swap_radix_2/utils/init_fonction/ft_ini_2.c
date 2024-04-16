#include "../../push_swap.h"

size_t	ft_all_numb(char *str, t_stacks *s, size_t i)
{
	size_t	k;
	size_t	add_it;
	size_t	j;

	k = 0;
	add_it = ft_count_words(str, ' ');
	while (add_it > k)
	{
		while (*str && *str != '-' && (*str < '0' || *str > '9'))
			str++;
		if (*str == '\0')
			break ;
		if (ft_there_is_number(str) != 0)
		{
			s->a[i] = ft_atol(str);
			i++;
			j = how_long(s->a[i - 1]);
			k++;
			str = str + j;
		}
		else
			return (i);
	}
	return (i);
}

size_t	next_value(char *str, size_t i)
{
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		i++;
	return (i);
}

void	add_value_stack(char **argv, t_stacks *s)
{
	size_t	i;
	size_t	j;
	size_t	k;

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
