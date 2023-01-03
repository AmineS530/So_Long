/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:51:32 by asadik            #+#    #+#             */
/*   Updated: 2022/10/26 18:30:36 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	i = 0;
	slen = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dstsize == 0)
		return (slen);
	while (src[i] && i + dlen < dstsize - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	if (dlen > dstsize)
		return (dstsize + slen);
	return (dlen + slen);
}
