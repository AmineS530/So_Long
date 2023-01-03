/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:57:11 by asadik            #+#    #+#             */
/*   Updated: 2022/10/27 12:52:23 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*del || !lst)
		return ;
	tmp = (*lst);
	while (lst && *lst)
	{
		if (tmp != NULL)
		{
			while (tmp != NULL)
			{
				tmp = (*lst)->next;
				del((*lst)->content);
				free (*lst);
				*lst = tmp;
			}
		}
		else
			break ;
	}
	return ;
}
