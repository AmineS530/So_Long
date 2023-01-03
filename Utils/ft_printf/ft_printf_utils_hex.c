/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:54:15 by asadik            #+#    #+#             */
/*   Updated: 2022/11/05 20:59:08 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int n, char x, int *len)
{
	int		base;
	char	*hex;

	base = 16;
	if (x == 'x')
		hex = HEX_LOWER;
	else
		hex = HEX_UPPER;
	if (n < (unsigned int )base)
		ft_putchar(hex[n % base], len);
	else
	{
		ft_putnbr_hex((n / base), x, len);
		ft_putnbr_hex((n % base), x, len);
	}
}

void	ft_putnbr_longhex(unsigned long long n, int *len)
{
	int		base;

	base = 16;
	if (n < (unsigned long long)base)
		ft_putchar(HEX_LOWER[n % base], len);
	else
	{
		ft_putnbr_longhex((n / base), len);
		ft_putnbr_longhex((n % base), len);
	}
}

void	ft_putaddr(void *n, int *len)
{
	unsigned long long	owo;

	owo = (unsigned long long)n;
	ft_putstr("0x", len);
	ft_putnbr_longhex(owo, len);
}
