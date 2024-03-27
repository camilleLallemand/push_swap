/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:13:08 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 17:10:39 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char const *s)
{
	size_t	i;
	char	*cp;

	i = 0;
	cp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!cp)
		return (NULL);
	while (s[i])
	{
		cp[i] = s[i];
		i++;
	}
	return (cp);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (!f)
		return (ft_strcpy(s));
	str = malloc(sizeof(char) * (ft_strlen(s) +1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
