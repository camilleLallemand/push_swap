/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_numb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:23:50 by calallem          #+#    #+#             */
/*   Updated: 2023/12/13 04:04:12 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	howlonginthex(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

static char	*changeorder(char *n)
{
	int		i;
	int		i2;
	int		size;
	char	stock;

	size = ft_strlen(n);
	i = 0;
	i2 = size - 1;
	while (i < (size - 1) / 2)
	{
		stock = n[i];
		n[i] = n[i2];
		n[i2] = stock;
		i++;
		i2--;
	}
	return (n);
}

char	*conv_to_hex(long nb, int type)
{
	char	*nbr;
	int		i;
	char	letter;

	i = 0;
	letter = 'a';
	nbr = malloc(sizeof(char) * howlonginthex(nb) + 1);
	if (type == 0)
		letter = 'A';
	if (!nbr)
		return (0);
	while (nb != 0)
	{
		if ((nb % 16) < 10)
			nbr[i] = ((nb % 16) + '0');
		else
			nbr[i] = ((nb % 16) - 10 + letter);
		i++;
		nb = nb / 16;
	}
	nbr[i] = '\0';
	return (changeorder(nbr));
}

void	print_point(void *i, int *hmchar)
{
	if (!i)
	{
		write (1, "(nil)", 5);
		(*hmchar) = (*hmchar)+5;
	}
	else{
		write (1, "0x", 2);
		(*hmchar) = (*hmchar) + 2;
		ft_putstr(conv_to_hex((long long)i, 0), hmchar);
	}
}

void ft_unsigned_putnbr(unsigned int n, int *hmchar)
{
	char	a;

	if (n > 9)
	{
		a = '0' + (n % 10);
		ft_unsigned_putnbr(n / 10, hmchar);
		ft_putchar(a, hmchar);
	}
	else
	{
		a = '0' + n;
		ft_putchar(a, hmchar);
	}
}
