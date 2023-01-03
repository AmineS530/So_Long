/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:51:27 by asadik            #+#    #+#             */
/*   Updated: 2022/10/17 12:54:28 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	owo;
	size_t	slen;

	owo = 0;
	slen = ft_strlen(src);
	if (!size)
		return (slen);
	while (src[owo] && owo < size - 1)
	{
		dest[owo] = src[owo];
		owo++;
	}
	dest[owo] = '\0';
	return (slen);
}
