/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:06:22 by asadik            #+#    #+#             */
/*   Updated: 2023/01/18 17:42:28 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"errors.h"

void	ft_close_window(void *ptr, void *win)
{
	mlx_destroy_window(ptr, win);
	ft_printf("%s You have closed the game %s", RED, DEFAULT);
	exit(0);
}
