/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:02 by asadik            #+#    #+#             */
/*   Updated: 2023/01/10 17:11:23 by asadik           ###   ########.fr       */
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
					objs->x * 69, objs->y * 69);
			if (objs->map[objs->y][objs->x] == '1')
				mlx_put_image_to_window(objs->ptr, objs->win, objs->wall,
					objs->x * 69, objs->y * 69);
			if (objs->map[objs->y][objs->x] == 'P')
				mlx_put_image_to_window(objs->ptr, objs->win, objs->player,
					objs->x * 69, objs->y * 69);
			if (objs->map[objs->y][objs->x] == 'C')
				mlx_put_image_to_window(objs->ptr, objs->win, objs->coin,
					objs->x * 69, objs->y * 69);
			objs->x++;
		}
		free (objs->map[objs->y]);
		objs->y++;
	}
		free (objs->map);
}

t_mapinfo	map_renderer(t_mapinfo rdr)
{
	rdr.ptr = mlx_init();
	rdr.width = 69;
	rdr.height = 69;
	rdr.y = 0;
	rdr.win = mlx_new_window(rdr.ptr, rdr.res * 69,
			rdr.line_count * 69, "so_long");
	rdr.wall = mlx_xpm_file_to_image(rdr.ptr, "./Textures/Texture_1.xpm",
			&rdr.width, &rdr.height);
	rdr.player = mlx_xpm_file_to_image(rdr.ptr, "./Textures/move01.xpm",
			&rdr.width, &rdr.height);
	rdr.coin = mlx_xpm_file_to_image(rdr.ptr, "./Textures/ender_eye.xpm",
			&rdr.width, &rdr.height);
	rdr.backg = mlx_xpm_file_to_image(rdr.ptr, "./Textures/Texture_2.xpm",
			&rdr.width, &rdr.height);
	render_objs(&rdr);
	mlx_loop(rdr.ptr);
	return(rdr);
}

// int	main(int argc, char *argv[])
// {
// 	t_mapinfo	rdr;

// 	if (argc == 2)
// 	{
// 		rdr = process_map(rdr);
// 		while (1)
// 		{
// 			/* code */
// 		}

// 		//map_renderer(rdr);
// 	}
// 	ft_printf("I quote \"%sYou didn't include a map, YOU DUCK%s\",%s Yuki%s",
// 		YELLOW, DEFAULT, CYAN, DEFAULT);
// 	return (0);
// }
