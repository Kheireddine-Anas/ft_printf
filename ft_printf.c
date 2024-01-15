/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:38:17 by akheired          #+#    #+#             */
/*   Updated: 2024/01/15 14:38:17 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_funcs.h"

int	spcfs(va_list ptr, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_printc(va_arg(ptr, int));
	else if (c == 's')
		i += ft_prints(va_arg(ptr, char *));
	else if (c == 'd' || c == 'i')
		i += ft_printd(va_arg(ptr, int));
	else if(c == 'u')
		i += ft_printu(va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		i += ft_printhex(va_arg(ptr, unsigned int), c);
	else if (c == 'p')
	{
		i += ft_prints("0x");
		i += ft_printadd(va_arg(ptr, unsigned long int));
	}
	else if (c == '%')
		i += ft_printc(va_arg(ptr, int));
	else
		i += ft_printc(c);
	return (i);
}

int ft_printf(char *str, ...)
{
	int	i;

	i = 0;
    va_list	ptr;
    va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += spcfs(ptr, *str);
		}
		else
			i += ft_printc(*str);
		str++;
	}
    va_end(ptr);
    return (i);
}
