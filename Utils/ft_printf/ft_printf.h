/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:22:54 by asadik            #+#    #+#             */
/*   Updated: 2022/11/05 20:59:35 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *param_name, ...);
void	ft_putchar(char c, int *len);
int		ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_unsigned(unsigned int n, int *len);
void	ft_putnbr_hex(unsigned int n, char x, int *len);
void	ft_putaddr(void *n, int *len);

#endif
