/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:18:58 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 17:09:48 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_char(int n)
{
	size_t	i;
	int		sign;

	sign = n;
	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (sign < 0)
		i++;
	return (i);
}

static char	*creat_tab(int n)
{
	size_t	size;
	char	*s;

	size = num_char(n);
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	s[size] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	size;

	size = num_char(n) - 1;
	s = creat_tab(n);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		s[size] = 48 -(n % 10);
		n = -(n / 10);
		size--;
	}
	while (n != 0)
	{
		s[size] = n % 10 + 48;
		n = n / 10;
		size --;
	}
	return (s);
}
