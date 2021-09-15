/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:43:14 by sadjigui          #+#    #+#             */
/*   Updated: 2021/09/07 15:47:14 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d_i(va_list convert, t_struct *v)
{
	int	result;

	result = va_arg(convert, int);
	ft_putnbr_fd(result, v);
}

void	ft_c(va_list convert, t_struct *v)
{
	int	c;

	c = va_arg(convert, int);
	write(1, &c, 1);
	v->g_return++;
}

void	ft_s(va_list convert, t_struct *v)
{
	char	*s;

	s = va_arg(convert, char *);
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s, v);
		s++;
	}
}

void	ft_u(va_list convert, t_struct *v)
{
	unsigned int	result;

	result = va_arg(convert, unsigned int);
	ft_putnbr_fd_unsigned(result, v);
}
