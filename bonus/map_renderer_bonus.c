/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:02 by asadik            #+#    #+#             */
/*   Updated: 2023/01/16 16:57:45 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_mapinfo	map_renderer(t_mapinfo rdr)
{
	rdr.ptr = mlx_init();
	set_cords(&rdr);
	rdr.y = 0;
	rdr.width = RES * rdr.player_x;
	rdr.height = RES * rdr.player_y;
	ft_put_xpm(&rdr);
	render_objs(&rdr);
	mlx_hook(rdr.win, 2, (1L << 0), ft_input, &rdr);
	mlx_loop(rdr.ptr);
	return (rdr);
}

void	render_objs(t_mapinfo *sy)
{
	sy->y = 0;
	while (sy->map[sy->y])
	{
		sy->x = 0;
		while (sy->map[sy->y][sy->x])
		{
			ft_put_images(sy);
			sy->x++;
		}
		sy->y++;
	}
}

void	ft_put_xpm(t_mapinfo *fs)
{
	fs->win = mlx_new_window(fs->ptr, fs->res * RES,
			fs->line_count * RES, "so_long");
	fs->exit_open = mlx_xpm_file_to_image(fs->ptr, "./Textures/End_portal.xpm",
			&fs->width, &fs->height);
	fs->exit = mlx_xpm_file_to_image(fs->ptr, "./Textures/End_portal_close.xpm",
			&fs->width, &fs->height);
	fs->wall = mlx_xpm_file_to_image(fs->ptr, "./Textures/Bedwock.xpm",
			&fs->width, &fs->height);
	fs->player_left = mlx_xpm_file_to_image(fs->ptr, "./Textures/look_left.xpm",
			&fs->width, &fs->height);
	fs->player_up = mlx_xpm_file_to_image(fs->ptr, "./Textures/look_up.xpm",
			&fs->width, &fs->height);
	fs->player_right = mlx_xpm_file_to_image(fs->ptr,
			"./Textures/look_right.xpm", &fs->width, &fs->height);
	fs->coin = mlx_xpm_file_to_image(fs->ptr, "./Textures/ender_eye_1.xpm",
			&fs->width, &fs->height);
	fs->backg = mlx_xpm_file_to_image(fs->ptr, "./Textures/Texture_2.xpm",
			&fs->width, &fs->height);
	fs->win_screen = mlx_xpm_file_to_image(fs->ptr, "./Textures/win.xpm",
			&fs->width, &fs->height);
	fs->player = fs->player_right;
}

void	ft_put_images(t_mapinfo *sy)
{
	if (sy->map[sy->y][sy->x] == '1')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->wall,
			sy->x * RES, sy->y * RES);
	if (sy->map[sy->y][sy->x] == 'P' || sy->map[sy->y][sy->x] == 'C' ||
			sy->map[sy->y][sy->x] == 'E' || sy->map[sy->y][sy->x] == '0')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->backg,
			sy->x * RES, sy->y * RES);
	if (sy->map[sy->y][sy->x] == 'E')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->exit,
			sy->x * RES, sy->y * RES);
	if (sy->map[sy->y][sy->x] == 'P')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->player,
			sy->player_x * RES, sy->player_y * RES);
	if (sy->map[sy->y][sy->x] == 'C')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->coin,
			sy->x * RES, sy->y * RES);
}
