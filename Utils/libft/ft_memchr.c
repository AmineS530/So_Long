/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:25 by asadik            #+#    #+#             */
/*   Updated: 2022/10/12 19:43:39 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*owo;
	size_t			i;

	i = 0;
	owo = ((unsigned char *) s);
	while (i < n)
	{
		if (owo[i] == ((unsigned char) c))
			return (&owo[i]);
		i++;
	}
	return (0);
}
