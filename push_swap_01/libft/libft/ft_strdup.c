/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 05:07:41 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 17:10:11 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*cp;

	i = 0;
	while (s[i])
		i++;
	cp = malloc((sizeof(char)) * (i + 1));
	if (!cp)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
