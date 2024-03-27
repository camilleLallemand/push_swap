/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 05:06:25 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 16:59:08 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_here(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ns;

	start = 0;
	i = 0;
	end = ft_strlen(s1) - 1;
	if (!s1)
		return (0);
	while (is_here(set, s1[start]) == 1)
		start++;
	if (s1[start] == 0)
		return (ft_strdup(""));
	while (is_here(set, s1[end]) == 1)
		end--;
	if (start > end)
		return (0);
	ns = malloc(sizeof(char) * (end - start + 2));
	if (!ns)
		return (0);
	ft_memcpy(ns, (s1 + start), (end - start + 1));
	ns[end - start + 1] = '\0';
	return (ns);
}
