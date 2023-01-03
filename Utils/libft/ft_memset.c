/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:17:55 by asadik            #+#    #+#             */
/*   Updated: 2022/10/26 11:47:41 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	uwu;

	uwu = 0;
	while (uwu < len)
	{
		((char *) s)[uwu] = (unsigned char) c;
		uwu++;
	}
	return (s);
}
