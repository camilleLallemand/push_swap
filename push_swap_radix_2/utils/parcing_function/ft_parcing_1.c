#include "../../push_swap.h"

int	is_only_number(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && (s[i] != '-' && s[i] != ' '))
			return (-1);
		i++;
	}
	return (1);
}

int	no_space_number_2(char *s, size_t *i, int *numb, int *sign)
{
	while (s[*i])
	{
		if (*sign != 0 && (s[*i] < '0' || s[*i] > '9'))
			return (-1);
		if (s[*i] >= '0' && s[*i] <= '9')
		{
			*numb += 1;
			*sign = 0;
		}
		if ((s[*i] == '-' || s[*i] == '+') && *numb != 0)
			return (-1);
		if (s[*i] == ' ' && *numb != 0)
			*numb = 0;
		if (s[*i] == '-' || s[*i] == '+')
			*sign += 1;
		*i += 1;
	}
	return (1);
}

int	no_space_numb(char *s)
{
	size_t	i;
	int		numb;
	int		sign;

	i = 0;
	numb = 0;
	sign = 0;
	if (no_space_number_2(s, &i, &numb, &sign) == -1)
		return (-1);
	if (sign != 0)
		return (-1);
	return (1);
}

int	is_only_space(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (1);
		i++;
	}
	return (-1);
}
