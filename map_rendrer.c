#include "so_long.h"

void	render_objs(t_mapinfo *objs)
{
	objs->width = 69;
	objs->height = 69;
	objs->wall = mlx_xpm_file_to_image(objs->ptr, "./Textures/Texture_1.xpm", &objs->width, &objs->height);
	objs->player = mlx_xpm_file_to_image(objs->ptr, "./Textures/move01.xpm", &objs->width, &objs->height);
	objs->coin = mlx_xpm_file_to_image(objs->ptr, "./Textures/ender_eye.xpm", &objs->width, &objs->height);
	objs->background = mlx_xpm_file_to_image(objs->ptr, "./Textures/Texture_2.xpm", &objs->width, &objs->height);
	objs->y = 0;
	while(objs->map[objs->y])
	{
		objs->x = 0;
		while(objs->map[objs->y][objs->x])
		{
			if (objs->map[objs->y][objs->x] == 'P' || objs->map[objs->y][objs->x] == 'C' ||
				objs->map[objs->y][objs->x] == 'E' || objs->map[objs->y][objs->x] == '0')
				mlx_put_image_to_window(objs->ptr , objs->win , objs->background , objs->x * 69, objs->y * 69);
			if (objs->map[objs->y][objs->x] == '1')
				mlx_put_image_to_window(objs->ptr , objs->win , objs->wall , objs->x * 69, objs->y * 69);
			if (objs->map[objs->y][objs->x] == 'P')
				mlx_put_image_to_window(objs->ptr , objs->win , objs->player , objs->x * 69, objs->y * 69);
			if (objs->map[objs->y][objs->x] == 'C')
				mlx_put_image_to_window(objs->ptr , objs->win , objs->coin , objs->x * 69, objs->y * 69);
			objs->x++;
		}
		objs->y++;
	}
}

void	map_renderer(t_mapinfo rdr)
{
	rdr.ptr = mlx_init();
	rdr.win = mlx_new_window(rdr.ptr, rdr.res * 69, rdr.line_count * 69, "so_long");

	render_objs(&rdr);
	mlx_loop(rdr.ptr);
}

int main(int argc, char *argv[])
{
	t_mapinfo rdr;
	if (argc == 2)
	{
		rdr = process_map(argv[1]);
		map_renderer(rdr);
	}
	ft_printf("you didnt select a map you retard");
	return (0);
}
