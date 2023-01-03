/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:43:28 by asadik            #+#    #+#             */
/*   Updated: 2022/11/05 20:57:14 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

int	ft_putstr(char *s, int *len)
{
	if (!s)
		ft_putstr("(null)", len);
	else
		while (*s)
			(*len) += write (1, s++, 1);
	return (*len);
}

void	ft_putnbr(int n, int *len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb = -nb;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0', len);
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, len);
		ft_putnbr_unsigned(n % 10, len);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0', len);
}
