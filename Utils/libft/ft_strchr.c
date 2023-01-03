/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:21:49 by asadik            #+#    #+#             */
/*   Updated: 2022/10/17 18:40:31 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*uwu;
	char	owo;

	i = 0;
	owo = ((char)c);
	uwu = ((char *)s);
	while (uwu[i] != owo && uwu[i] != '\0')
	{
		if (uwu[i] == owo)
		{
			return (&uwu[i]);
		}
		i++;
	}
	if (uwu[i] == owo)
	{
		return (&uwu[i]);
	}
	return (0);
}
