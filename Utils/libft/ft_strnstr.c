/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:23:00 by asadik            #+#    #+#             */
/*   Updated: 2022/10/26 18:29:00 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getresults(const char *haystack, const char *needle, size_t len,
		size_t i)
{
	size_t	j;

	j = 0;
	if (haystack[i] == needle[j])
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)(haystack + i));
			}
			j++;
		}
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;
	char	*uwu;

	i = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return (((char *)haystack));
	nlen = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		uwu = ft_getresults(haystack, needle, len, i);
		if (uwu != NULL)
			return (uwu);
		i++;
	}
	return (NULL);
}
