/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:33:19 by asadik            #+#    #+#             */
/*   Updated: 2023/01/03 13:55:15 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	coversions(va_list ap, const char param_name, int *len)
{
	if (param_name == 'c')
		ft_putchar ((char)va_arg(ap, int), len);
	if (param_name == 's')
		ft_putstr(va_arg(ap, char *), len);
	if (param_name == 'p')
		ft_putaddr(va_arg(ap, void *), len);
	if (param_name == 'd' || param_name == 'i')
		ft_putnbr(va_arg(ap, int), len);
	if (param_name == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int), len);
	if (param_name == 'x')
		ft_putnbr_hex(va_arg(ap, unsigned int), 'x', len);
	if (param_name == 'X')
		ft_putnbr_hex(va_arg(ap, unsigned int), 'X', len);
	if (param_name == '%')
		ft_putchar('%', len);
	else
		return ;
}

int	ft_printf(const char *param_name, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, param_name);
	while (*param_name)
	{
		if (*param_name == '%')
		{
			param_name++;
			coversions(ap, *param_name, &len);
		}
		else
			ft_putchar(*param_name, &len);
		param_name++;
	}
	va_end(ap);
	return (len);
}
