/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:00:11 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 16:29:42 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ch;
	unsigned char	*le;

	ch = (unsigned char *) dest;
	le = (unsigned char *) src;
	while (n -- && (ch || le))
	{
		*ch++ = *le++;
	}
	return (dest);
}
