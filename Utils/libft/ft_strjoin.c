/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:52:24 by asadik            #+#    #+#             */
/*   Updated: 2023/01/10 19:21:14 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	j;
	char	*joined;

	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = -1;
	j = -1;
	joined = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!joined)
		return (NULL);
	while (++i < s1len)
		*(joined + i) = s1[i];
	while ((i + ++j) < (s1len + s2len))
		*(joined + i + j) = s2[j];
	*(joined + i + j) = '\0';
	free ((void *)s1);
	free ((void *)s2);
	return (joined);
}
