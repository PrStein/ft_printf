/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:58:59 by sadjigui          #+#    #+#             */
/*   Updated: 2021/09/07 15:13:46 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upper_x(va_list convert, t_struct *v)
{
	unsigned int	j;

	j = va_arg(convert, unsigned int);
	ft_putnbr_base(j, "0123456789ABCDEF", v);
}

void	ft_low_x(va_list convert, t_struct *v)
{
	unsigned int	j;

	j = va_arg(convert, unsigned int);
	ft_putnbr_base(j, "0123456789abcdef", v);
}

void	ft_putp(unsigned long nb, char *base, t_struct *v)
{
	if (nb < 0)
		nb = nb * -1;
	if (nb % 16 != nb)
		ft_putp(nb / 16, base, v);
	ft_putchar(base[nb % 16], v);
}

void	ft_p(va_list convert, t_struct *v)
{
	unsigned long	s;

	s = va_arg(convert, unsigned long);
	ft_putchar('0', v);
	ft_putchar('x', v);
	ft_putp(s, "0123456789abcdef", v);
}
