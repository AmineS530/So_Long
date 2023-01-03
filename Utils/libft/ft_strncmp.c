/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:38:11 by asadik            #+#    #+#             */
/*   Updated: 2022/10/20 18:05:17 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*aya;
	unsigned char	*awa;
	size_t			i;

	aya = ((unsigned char *) s1);
	awa = ((unsigned char *) s2);
	i = 0;
	if (n == 0)
		return (0);
	while (aya[i] == awa[i] && aya[i] && awa[i] && i < n - 1)
		i++;
	return (aya[i] - awa[i]);
}
