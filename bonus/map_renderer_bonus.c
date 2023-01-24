/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:12:43 by asadik            #+#    #+#             */
/*   Updated: 2023/01/24 15:47:23 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_mapinfo	map_renderer(t_mapinfo rdr)
{
	rdr.ptr = mlx_init();
	rdr.moves_counter = 0;
	rdr.y = 0;
	rdr.width = RES * rdr.player_x;
	rdr.height = RES * rdr.player_y;
	ft_put_xpm(&rdr);
	render_objs(&rdr);
	mlx_loop_hook(rdr.ptr, ft_animate_enemy, &rdr);
	mlx_hook(rdr.win, 2, (1L << 0), ft_input, &rdr);
	mlx_hook(rdr.win, 17, (1L << 0), ft_exit, &rdr);
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
			sy->display_move = ft_itoa(sy->moves_counter);
			ft_put_images(sy);
			mlx_string_put(sy->ptr, sy->win, (sy->res / 2) * RES, 10,
				0x00FFFFFF, sy->display_move);
			sy->x++;
			free (sy->display_move);
		}
		sy->y++;
	}
}

void	ft_put_xpm(t_mapinfo *fs)
{
	fs->win = mlx_new_window(fs->ptr, fs->res * RES,
			fs->line_count * RES, "so_long_bonus");
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
	fs->coin = mlx_xpm_file_to_image(fs->ptr, "./Textures/ender_egg.xpm",
			&fs->width, &fs->height);
	fs->backg = mlx_xpm_file_to_image(fs->ptr, "./Textures/end_block.xpm",
			&fs->width, &fs->height);
	ft_another_put_xpm(fs);
	fs->enemy = fs->enemy1;
	fs->player = fs->player_right;
}

void	ft_put_images(t_mapinfo *sy)
{
	if (sy->map[sy->y][sy->x] == '1')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->wall,
			sy->x * RES, sy->y * RES);
	if (sy->map[sy->y][sy->x] == 'P' || sy->map[sy->y][sy->x] == 'C' ||
			sy->map[sy->y][sy->x] == 'E' || sy->map[sy->y][sy->x] == '0'
			|| sy->map[sy->y][sy->x] == 'F')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->backg,
			sy->x * RES, sy->y * RES);
	if (sy->map[sy->y][sy->x] == 'E')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->exit,
			sy->x * RES, sy->y * RES);
	if (sy->map[sy->y][sy->x] == 'F')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->enemy,
			sy->x * RES, sy->y * RES);
	if (sy->map[sy->y][sy->x] == 'P')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->player,
			sy->player_x * RES, sy->player_y * RES);
	if (sy->map[sy->y][sy->x] == 'C')
		mlx_put_image_to_window(sy->ptr, sy->win, sy->coin,
			sy->x * RES, sy->y * RES);
}
