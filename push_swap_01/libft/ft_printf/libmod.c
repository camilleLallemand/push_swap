/* ************************************************************************** */
/*
  */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+
  */
/*   Created: 2023/11/07 20:45:39 by calallem          #+#    #+#
  */
/*   Updated: 2023/11/22 16:42:26 by calallem         ###   ########.fr       */
/*
  */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(char c, int *total)
{
        write(1, &c, 1);
	(*total)++;
}

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

void    ft_putstr(char *s, int *total)
{
        size_t  i;

        i = 0;
        while (s[i])
        {
                ft_putchar(s[i], total);
                i++;
        }
}

void    ft_putnbr(int n, int *total)
{
        char    a;

        if (n < -9)
        {
                a = '0' + -(n % 10);
                ft_putchar('-', total);
                ft_putnbr(-(n / 10), total);
                ft_putchar(a, total);
        }
        else if (n < 0)
        {
                ft_putchar('-', total);
                ft_putnbr(-n, total);
	}
        else if (n > 9)
        {
                a = '0' + (n % 10);
                ft_putnbr(n / 10, total);
                ft_putchar(a, total);
        }
        else
        {
                a = '0' + n;
                ft_putchar(a, total);
        }
}
