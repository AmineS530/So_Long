/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:49:15 by asadik            #+#    #+#             */
/*   Updated: 2022/10/08 12:24:24 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aya;
	unsigned char	*awa;
	size_t			i;

	i = 0;
	aya = ((unsigned char *) s1);
	awa = ((unsigned char *) s2);
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (aya[i] != awa[i])
			return (aya[i] - awa[i]);
		i++;
	}
	return (0);
}
