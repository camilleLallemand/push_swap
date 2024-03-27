/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:53:02 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 17:52:15 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		memo;
	size_t	i;
	char	*src;

	i = 0;
	memo = -1;
	src = (char *)s;
	while (s[i])
	{
		if (s[i] == (char) c)
			memo = i;
		i++;
	}
	if (s[i] == (char) c)
		return (&src[i]);
	if (memo >= 0)
		return (&src[memo]);
	return (0);
}
