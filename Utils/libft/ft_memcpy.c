/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:07:54 by asadik            #+#    #+#             */
/*   Updated: 2022/10/26 14:57:03 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	unsigned char	*sr;
	unsigned char	*ds;

	i = 0;
	if (!dest && !src)
		return (0);
	if (dest == src || !n)
		return (dest);
	sr = ((unsigned char *)src);
	ds = ((unsigned char *)dest);
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (ds);
}
