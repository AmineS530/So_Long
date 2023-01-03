/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:31:20 by asadik            #+#    #+#             */
/*   Updated: 2022/10/27 15:40:53 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revtab(char *str, int negative)
{
	int	array_e;
	int	array_b;
	int	tmp;

	array_e = (ft_strlen(str) - 1);
	array_b = negative;
	tmp = 0;
	while (array_b < array_e)
	{
		tmp = str[array_b];
		str[array_b] = str[array_e];
		str[array_e] = tmp;
		array_b++;
		array_e--;
	}
	return (str);
}

static int	ft_nbr_len(long nb)
{
	long	uwu;
	int		owo;

	uwu = nb;
	owo = 0;
	if (uwu == 0)
		return (1);
	if (uwu < 0)
	{
		owo++;
		uwu *= -1;
	}
	while (uwu)
	{
		uwu /= 10;
		owo++;
	}
	return (owo);
}

static	void	yaleghderbda(long nb, char *results, int uwu)
{
	while (nb > 0)
	{
		*(results + uwu++) = ((nb % 10) + '0');
		nb /= 10;
	}
	*(results + uwu) = '\0';
}

char	*ft_itoa(int n)
{
	int		uwu;
	char	*results;
	int		neg;
	long	nb;

	nb = ((long)n);
	neg = 0;
	results = malloc(sizeof(char) * ft_nbr_len(nb) + 1);
	if (!results)
		return (NULL);
	uwu = 0;
	if (nb == 0)
		*(results + uwu++) = '0';
	if (nb < 0)
	{
		nb *= -1;
		*(results + uwu++) = '-';
		neg = 1;
	}
	yaleghderbda(nb, results, uwu);
	return (ft_revtab(results, neg));
}
