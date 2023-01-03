/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:53:43 by asadik            #+#    #+#             */
/*   Updated: 2022/10/27 14:58:37 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(const char *set, char c)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	lenif(const char *s1)
{
	if (ft_strlen(s1) > 0)
		return (ft_strlen(s1) - 1);
	else
		return (ft_strlen(s1));
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*owo;

	i = 0;
	len = 0;
	if (!s1)
		return (NULL);
	while (is_valid(set, *(s1)))
		s1++;
	len = lenif(s1);
	while (is_valid(set, s1[len]))
		len--;
	owo = malloc(sizeof(char) * len + 2);
	if (!owo)
		return (NULL);
	while (i < len + 1)
	{
		owo[i] = s1[i];
		i++;
	}
	owo[i] = '\0';
	return (owo);
}
