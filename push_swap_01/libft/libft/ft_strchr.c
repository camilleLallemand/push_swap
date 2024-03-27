/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:45:10 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 17:51:28 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*src;

	i = 0;
	src = (char *)s;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&src[i]);
		i++;
	}
	if (s[i] == (char) c)
		return (&src[i]);
	return (0);
}
