/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:05:22 by asadik            #+#    #+#             */
/*   Updated: 2023/01/24 10:51:11 by asadik           ###   ########.fr       */
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

	i++;
	if (i == 50)
	{
		m->enemy = m->enemy0;
		render_objs(m);
	}
	if (i == 250)
	{
		m->enemy = m->enemy1;
		render_objs(m);
	}
	if (i == 750)
	{
		m->enemy = m->enemy2;
		render_objs(m);
	}
	if (i == 1500)
		i = 0;
	return (i);
}
