/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:18:06 by sadjigui          #+#    #+#             */
/*   Updated: 2021/09/10 15:49:43 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_struct
{
	int	g_return;

}	t_struct;

void	ft_d_i(va_list convert, t_struct *v_return);
void	ft_c(va_list convert, t_struct *v_return);
void	ft_s(va_list convert, t_struct *v_return);
void	ft_u(va_list convert, t_struct *v_return);
void	ft_putnbr_fd_unsigned(unsigned int n, t_struct *v_return);
void	ft_putchar(char c, t_struct *v_return);
void	ft_putnbr_fd(int n, t_struct *v_return);
void	ft_putnbr_base(unsigned int nbr, char *base, t_struct *v_return);
void	ft_low_x(va_list convert, t_struct *v_return);
void	ft_upper_x(va_list convert, t_struct *v_return);
void	ft_p(va_list convert, t_struct *v_return);
void	ft_putp(unsigned long nb, char *base, t_struct *v_return);
int		ft_printf(const char *str, ...);

#endif
