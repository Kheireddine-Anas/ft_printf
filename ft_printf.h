/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:38:06 by akheired          #+#    #+#             */
/*   Updated: 2024/01/15 14:38:06 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char *str, ...);
int	ft_printc(char c);
int	ft_prints(char *s);
int	ft_printd(int n);
int	ft_printu(unsigned int num);
int	ft_printhex(unsigned long num, char xX);
int	ft_printadd(unsigned long int num);

#endif