/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:06:28 by asadik            #+#    #+#             */
/*   Updated: 2022/10/07 20:36:21 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	owo;

	sign = 1;
	owo = 0;
	result = 0;
	while ((str[owo] >= 9 && str[owo] <= 13) || str[owo] == ' ')
		owo++;
	while (str[owo] == '-' || str[owo] == '+')
	{
		if (str[owo + 1] == '-' || str[owo + 1] == '+')
			return (0);
		if (str[owo] == '-')
			sign *= -1;
		owo++;
	}
	while (str[owo] >= '0' && str[owo] <= '9')
	{
		result = result * 10;
		result += str[owo] - '0';
		owo++;
	}
	return (result * sign);
}
