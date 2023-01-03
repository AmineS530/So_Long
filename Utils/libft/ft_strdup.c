/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:15:59 by asadik            #+#    #+#             */
/*   Updated: 2022/10/09 13:44:42 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*mmal;

	len = ft_strlen(s1);
	mmal = malloc((len + 1) * sizeof(char));
	if (!mmal)
	{
		return (NULL);
	}
	ft_strcpy(mmal, s1);
	return (mmal);
}
