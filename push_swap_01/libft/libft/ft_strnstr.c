/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:38:53 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 16:53:14 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (*little == '\0')
		return ((char *) big);
	while (i < len && big[i])
	{
		i2 = 0;
		while (little[i2] && big[i + i2] == little[i2] && i + i2 < len)
		{
			i2++;
		}
		if (little[i2] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (0);
}
