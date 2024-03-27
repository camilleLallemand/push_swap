/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:41:43 by calallem          #+#    #+#             */
/*   Updated: 2023/12/13 06:09:19 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_form(va_list args, const char *str, size_t i, int *total)
{
	if (str[i] == 'c')
		ft_putchar((va_arg(args, int)), total);
	else if (str[i] == 's')
		ft_putstr((va_arg(args, char *)), total);
	else if (str[i] == 'p')
		print_point(va_arg(args, void *), total);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr((va_arg(args, int)), total);
	else if (str[i] == 'u')
		ft_unsigned_putnbr(va_arg(args, unsigned int), total);
	else if (str[i] == 'x')
		ft_putstr(conv_to_hex((va_arg(args, int)), 1), total);
	else if (str[i] == 'X')
		ft_putstr(conv_to_hex((va_arg(args, int)), 0), total);
	else if (str[i] == '%')
	{
		write(1, "%", 1);
		(*total)++;
	}
	else
		return (-1);
	return (*total);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int *total;

        total = malloc(sizeof(int));
        *total = 0;
	i = 0;
	va_start(args, str);
	while (i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_form(args, str, i, total) == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (*total);
}
#include<stdio.h>
int main(void)
{
	char *s;
	printf("\n%s%d\n","le vrai :",printf("%%x", 45555));
	printf("%s%d", "le miens :", ft_printf("%%x",45555));

	return 0;
}
