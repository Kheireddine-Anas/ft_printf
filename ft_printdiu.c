/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdiu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:08:07 by akheired          #+#    #+#             */
/*   Updated: 2024/01/15 15:08:07 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printd(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
		i += ft_printd(n);
	}
	else if (n > 9)
	{
		i += ft_printd(n / 10);
		i += ft_printd(n % 10);
	}
	else
	{
		i += ft_printc(n + 48);
	}
	return (i);
}

int	ft_printu(unsigned int num)
{
	int	i;

	i = 0;
	if (num < 10)
		i += ft_printc(num + 48);
	else
	{
		i += ft_printu(num / 10);
		i += ft_printu(num % 10);
	}
	return (i);
}
