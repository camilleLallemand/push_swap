/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:04:58 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 16:18:47 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnumeric(int c)
{
	if ((char) c > 47 && (char) c < 58)
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isnumeric(c))
		return (1);
	return (0);
}
/*
void main(void)
{
	printf("%d\n",ft_isalnum('{'));
	printf("%d\n",ft_isalnum(96));
	printf("%d\n",ft_isalnum('A'));
	printf("%d\n",ft_isalnum('Z'));
}*/
