/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:40:15 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 16:36:35 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	result;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	result = 0;
	i = 0;
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_len])
		src_len++;
	result = dest_len + src_len;
	if (dest_len < size)
	{
		while (src[i] && dest_len + i < size - 1)
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		dst[dest_len + i] = '\0';
	}
	return (result);
}
