/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:50:18 by calallem          #+#    #+#             */
/*   Updated: 2023/11/22 17:07:25 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n < -9)
	{
		a = '0' + -(n % 10);
		write(fd, "-", 1);
		ft_putnbr_fd(-(n / 10), fd);
		write(fd, &a, 1);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		a = '0' + (n % 10);
		ft_putnbr_fd(n / 10, fd);
		write(fd, &a, 1);
	}
	else
	{
		a = '0' + n;
		write(fd, &a, 1);
	}
}
