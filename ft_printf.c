/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:38:24 by sadjigui          #+#    #+#             */
/*   Updated: 2021/09/07 15:10:43 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_percent(const char *str, va_list convert, int i, t_struct *v)
{
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_d_i(convert, v);
	if (str[i + 1] == 'c')
		ft_c(convert, v);
	if (str[i + 1] == 's')
		ft_s(convert, v);
	if (str[i + 1] == 'u')
		ft_u(convert, v);
	if (str[i + 1] == 'p')
		ft_p(convert, v);
	if (str[i + 1] == 'x')
		ft_low_x(convert, v);
	if (str[i + 1] == 'X')
		ft_upper_x(convert, v);
	if (str[i + 1] == '%')
		ft_putchar('%', v);
}

static void	vf_print(const char *str, va_list convert, t_struct *v)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_percent(str, convert, i, v);
			i++;
		}
		else
		{
			ft_putchar(str[i], v);
		}
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		convert;
	t_struct	v;

	v.g_return = 0;
	va_start(convert, str);
	vf_print(str, convert, &v);
	va_end(convert);
	return (v.g_return);
}
