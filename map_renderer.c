/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:02 by asadik            #+#    #+#             */
/*   Updated: 2023/01/11 13:31:16 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_objs(t_mapinfo *objs)
{
	while (objs->map[objs->y])
	{
		objs->x = 0;
		while (objs->map[objs->y][objs->x])
		{
			if (objs->map[objs->y][objs->x] == 'P' ||
				objs->map[objs->y][objs->x] == 'C' ||
				objs->map[objs->y][objs->x] == 'E' ||
				objs->map[objs->y][objs->x] == '0')
				mlx_put_image_to_window(objs->ptr, objs->win, objs->backg,
					objs->x * RES, objs->y * RES);
			if (objs->map[objs->y][objs->x] == '1')
				mlx_put_image_to_window(objs->ptr, objs->win, objs->wall,
					objs->x * RES, objs->y * RES);
			if (objs->map[objs->y][objs->x] == 'P')
				mlx_put_image_to_window(objs->ptr, objs->win, objs->player,
					objs->x * RES, objs->y * RES);
			if (objs->map[objs->y][objs->x] == 'C')
				mlx_put_image_to_window(objs->ptr, objs->win, objs->coin,
					objs->x * RES, objs->y * RES);
			objs->x++;
		}
		objs->y++;
	}
}

t_mapinfo	*map_renderer(t_mapinfo rdr)
{
	rdr.ptr = mlx_init();
	rdr.y = 0;
	set_cords(&rdr);
	rdr.width = RES * rdr.player_x;
	rdr.height = RES * rdr.player_y;
	rdr.win = mlx_new_window(rdr.ptr, rdr.res * RES,
			rdr.line_count * RES, "so_long");
	rdr.wall = mlx_xpm_file_to_image(rdr.ptr, "./Textures/Texture_1.xpm",
			&rdr.width, &rdr.height);
	rdr.player = mlx_xpm_file_to_image(rdr.ptr, "./Textures/move01.xpm",
			&rdr.width, &rdr.height);
	rdr.coin = mlx_xpm_file_to_image(rdr.ptr, "./Textures/ender_eye.xpm",
			&rdr.width, &rdr.height);
	rdr.backg = mlx_xpm_file_to_image(rdr.ptr, "./Textures/Texture_2.xpm",
			&rdr.width, &rdr.height);
	rdr.next_frame = &rdr;
	render_objs(rdr.next_frame);
	mlx_loop(rdr.ptr);
	mlx_hook(rdr.win, )
	return (rdr.next_frame);
}

void	set_cords(t_mapinfo *xy)
{
	while (xy->map[xy->y])
	{
		xy->x = 0;
		while (xy->map[xy->y][xy->x])
		{
			if (xy->map[xy->y][xy->x] == 'P')
				{
					xy->player_x = xy->x;
					xy->player_y = xy->y;
				}
			if (xy->map[xy->y][xy->x] == 'C')
				xy->collectables_count++;
			if (xy->map[xy->y][xy->x] == 'E')
				{
					xy->exit_x = xy->x;
					xy->exit_y = xy->y;
				}
			xy->x++;
		}
		xy->y++;
	}
	xy->y = 0;
}
