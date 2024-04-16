#include "../../push_swap.h"

int	ft_pow(int n, int p)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < p)
	{
		res = res * n;
		i++;
	}
	return (res);
}

long long	long_to_bit(long n)
{
	long long	bit;
	long		i;

	bit = 0;
	i = 0;
	while (n > 0)
	{
		bit = bit + (n % 2) * ft_pow(10, i);
		n = n / 2;
		i++;
	}
	return (bit);
}

int	count_bits(long n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

void	radix_sort_binary(t_stacks *s)
{
	long	max_value;
	int		max_bits;
	int		i;
	int		size;

	max_value = get_max_value(s->a, s->a_size);
	max_bits = count_bits(max_value);
	i = 0;
	while (i < max_bits)
	{
		size = s->a_size;
		while (size--)
		{
			if (((s->a[0] >> i) & 1) == 0)
				pb(s);
			else
				ra(s);
		}
		i++;
		while (s->b_size > 0)
			pa(s);
	}
}
