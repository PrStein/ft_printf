/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:02:34 by sadjigui          #+#    #+#             */
/*   Updated: 2021/09/07 15:06:18 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, t_struct *v)
{
	write(1, &c, 1);
	v->g_return++;
}

void	ft_putnbr_fd(int n, t_struct *v)
{
	if (n < 0)
	{
		ft_putchar('-', v);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			v->g_return += 10;
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, v);
		ft_putnbr_fd(n % 10, v);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0', v);
	}
}

void	ft_putnbr_fd_unsigned(unsigned int n, t_struct *v)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, v);
		ft_putnbr_fd(n % 10, v);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0', v);
}

void	ft_putnbr_base(unsigned int nbr, char *base, t_struct *v)
{
	unsigned int	size;
	unsigned int	r;

	size = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-', v);
		r = (unsigned int)(-nbr);
	}
	else
		r = (unsigned int)nbr;
	if (r >= size)
	{
		ft_putnbr_base(r / size, base, v);
		ft_putnbr_base(r % size, base, v);
	}
	else
		ft_putchar(base[r % size], v);
}
