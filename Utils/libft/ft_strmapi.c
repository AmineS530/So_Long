/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:34:03 by asadik            #+#    #+#             */
/*   Updated: 2022/10/20 15:45:42 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mal;
	char	*awa;

	i = 0;
	if (!s || !f)
		return (NULL);
	awa = ((char *)s);
	mal = malloc(sizeof(char) * ft_strlen(awa) + 1);
	if (!mal)
		return (NULL);
	while (s[i])
	{
		*(mal + i) = f(i, awa[i]);
		i++;
	}
	*(mal + i) = '\0';
	return (mal);
}
