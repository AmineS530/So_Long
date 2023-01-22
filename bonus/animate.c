/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:05:22 by asadik            #+#    #+#             */
/*   Updated: 2023/01/22 20:56:50 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_another_put_xpm(t_mapinfo *anm)
{
	anm->enemy0 = mlx_xpm_file_to_image(anm->ptr, "./Textures/enderman_0.xpm",
			&anm->width, &anm->height);
	anm->enemy1 = mlx_xpm_file_to_image(anm->ptr, "./Textures/enderman_1.xpm",
			&anm->width, &anm->height);
	anm->enemy2 = mlx_xpm_file_to_image(anm->ptr, "./Textures/enderman_2.xpm",
			&anm->width, &anm->height);
}

int	ft_animate_enemy(t_mapinfo *m)
{
	static int	i;

	i = 0;
	i++;
	if (i == 0)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->enemy0,
			m->x * RES, m->y * RES);
	}
	if (i == 1)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->enemy1,
			m->x * RES, m->y * RES);
	}
	if (i == 2)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->enemy2,
			m->x * RES, m->y * RES);
	}
	if (i == 3)
		i = 0;
	return (0);
}
