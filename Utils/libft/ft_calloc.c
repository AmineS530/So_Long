/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:33:28 by asadik            #+#    #+#             */
/*   Updated: 2022/10/24 20:09:40 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*owo;
	size_t	total;

	total = (count * size);
	owo = malloc(total);
	if (!owo)
		return (NULL);
	ft_bzero(owo, total);
	return (owo);
}
