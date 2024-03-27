/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:31:03 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 16:31:11 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tempdest;
	unsigned char	*tempsrc;

	tempdest = (unsigned char *) dest;
	tempsrc = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (tempsrc < tempdest && (tempsrc + n) > tempdest)
	{
		tempdest = tempdest + n;
		tempsrc = tempsrc + n;
		while (n--)
			*--tempdest = *--tempsrc;
	}
	else
	{
		while (n--)
			*tempdest++ = *tempsrc++;
	}
	return (dest);
}
