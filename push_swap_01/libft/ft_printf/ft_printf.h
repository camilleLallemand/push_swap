/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:18:24 by calallem          #+#    #+#             */
/*   Updated: 2023/12/13 05:18:39 by calallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include <stddef.h>

int	ft_printf(const char *str, ...);

char	*conv_to_hex(long nb, int type);

size_t  ft_strlen(const char *s); 
void    ft_putnbr(int n, int *total); 
void    ft_putstr(char *s, int *total); 
void    ft_putchar(char c, int *total);

void	print_point(void *i, int *t);
void	ft_unsigned_putnbr(unsigned int n, int *t);
#endif
