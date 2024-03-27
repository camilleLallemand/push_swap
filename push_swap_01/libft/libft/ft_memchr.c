/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 04:35:13 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 16:46:13 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*scp;
	unsigned int		i;

	scp = (unsigned char *)s;
	i = 0;
	while (n --)
	{
		if (*scp == (unsigned char) c)
			return ((void *)(s + i));
		scp++;
		i++;
	}
	return (NULL);
}
