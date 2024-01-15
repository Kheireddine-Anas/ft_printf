/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:06:11 by akheired          #+#    #+#             */
/*   Updated: 2024/01/15 15:06:11 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(char c)
{
	return (write(1, &c, 1));
}

int	ft_prints(char *s)
{
	int	i;

	i = 0;
	if (!s)
		{i += ft_prints("(null)");
		return i;};
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
#include <stdio.h>
int main()
{
	// ft_printf("%x\n", 0xabcdef);
	// printf("%x", 0xabcdef);
	// ft_printf("%p\n", "");
	// printf("%p", "");
	printf("----%d---\n",ft_printf("_k%px%d2?ni%u_JFr%p%p\t43I D{:U%pQJEHAGS\tf@%p;:L7e%x|>%s{h<", (void *)-50637906729407355, -1509266757, -1335774814, (void *)-353672614918160985, (void *)1468829337266926668, (void *)-6691437165450536984, (void *)-1367014174128548009, 1258139719, "tyYgT\rbZ.},<1Us`0.sj8U&T%HMwo\"BYS!F~ 0jVfeYnGB;(~?eJIu19&$x"));
	printf("----%d---\n",printf("_k%px%d2?ni%u_JFr%p%p\t43I D{:U%pQJEHAGS\tf@%p;:L7e%x|>%s{h<", (void *)-50637906729407355, -1509266757, -1335774814, (void *)-353672614918160985, (void *)1468829337266926668, (void *)-6691437165450536984, (void *)-1367014174128548009, 1258139719, "tyYgT\rbZ.},<1Us`0.sj8U&T%HMwo\"BYS!F~ 0jVfeYnGB;(~?eJIu19&$x"));
}