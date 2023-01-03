/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:52:24 by asadik            #+#    #+#             */
/*   Updated: 2022/10/13 10:52:26 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	joined = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!joined)
		return (NULL);
	while (i < s1len)
	{
		*(joined + i++) = *(s1++);
	}
	while (i < (s1len + s2len))
	{
		*(joined + i++) = *(s2++);
	}
	*(joined + i) = '\0';
	return (joined);
}
