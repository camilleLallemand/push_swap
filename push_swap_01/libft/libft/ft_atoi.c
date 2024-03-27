/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: calallem <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/08 01:49:30 by calallem	       #+#    #+#	      */
/*   Updated: 2023/11/22 16:15:53 by calallem         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	overflow_atoi(long stock, int sign)
{
	long	check;

	check = (long) stock * 10;
	if (check / 10 != stock)
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	return (1);
}

static int	space_atoi(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long	stock;
	char	value;
	size_t	i;
	int		sign;

	value = 0;
	stock = 0;
	sign = 1;
	i = space_atoi(nptr);
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = nptr[i] - 48;
		if (overflow_atoi(stock, sign) != 1)
			return (overflow_atoi(stock, sign));
		stock = stock * 10 + value;
		i++;
	}
	return ((int) stock * sign);
}
