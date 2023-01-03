/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:30:46 by asadik            #+#    #+#             */
/*   Updated: 2022/10/28 21:04:51 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*awa;
	unsigned char	*aya;

	if (!dest && !src)
		return (NULL);
	awa = ((unsigned char *)src);
	aya = ((unsigned char *)dest);
	if (src < dest)
		while (n--)
			*(aya + n) = *(awa + n);
	else
		ft_memcpy(aya, awa, n);
	return (dest);
}
