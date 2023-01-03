/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:26:13 by asadik            #+#    #+#             */
/*   Updated: 2022/10/25 15:10:51 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*poggers;

	poggers = malloc(sizeof(t_list));
	if (!poggers)
		return (NULL);
	poggers->content = content;
	poggers->next = NULL;
	return (poggers);
}
