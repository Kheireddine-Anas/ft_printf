/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:10:03 by akheired          #+#    #+#             */
/*   Updated: 2024/01/15 15:10:03 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int num, char xX)
{
	char	*base;
	int		i;

	i = 0;
	if (xX == 'x')
		base = "0123456789abcdef";
	if (xX == 'X')
		base = "0123456789ABCDEF";
	if (num >= 16)
	{
		i += ft_printhex(num / 16, xX);
		i += ft_printhex(num % 16, xX);
	}
	else
		i += ft_printc(base[num]);
	return (i);
}

int	ft_printadd(unsigned long int num)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (num >= 16)
	{
		i += ft_printadd(num / 16);
		i += ft_printadd(num % 16);
	}
	else
		i += ft_printc(base[num]);
	return (i);
}
