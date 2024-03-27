/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:31:05 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 17:50:46 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	all;

	all = nmemb * size;
	if (all && all / nmemb != size)
		return (0);
	tab = malloc (nmemb * size);
	if (!tab)
		return (NULL);
	tab = ft_memset(tab, 0, (nmemb * size));
	return (tab);
}
