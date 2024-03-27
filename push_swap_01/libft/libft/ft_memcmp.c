/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:12:38 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 16:47:44 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cp;
	unsigned char	*s2cp;
	size_t			i;

	s1cp = (unsigned char *) s1;
	s2cp = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (n - 1 > i && s1cp[i] == s2cp[i])
	{
		i++;
	}
	return (s1cp[i] - s2cp[i]);
}
