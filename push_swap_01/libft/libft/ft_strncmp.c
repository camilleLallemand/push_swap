/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:05:46 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 16:44:33 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (((s1[0] == '\0') && (s2[0] == '\0')) || n == 0)
		return (0);
	while (s1[i] == s2[i] && s2[i] && s1[i] && i < n - 1)
		i++;
	if (ft_isascii(s1[i]) == 0 && s1[i] != s2[i])
		return (1);
	if (ft_isascii(s2[i]) == 0 && s1[i] != s2[i])
		return (-1);
	return (s1[i] - s2[i]);
}
