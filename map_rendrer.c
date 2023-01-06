#include "so_long.h"


void	map_renderer(t_mapinfo *rdr)
{
	int x;
	int y = 0;
	int width = 69;
	int height = 69;
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr,rdr->res * 69, rdr->line_count * 69, "so_long");
	void *wall = mlx_xpm_file_to_image(ptr, "./Textures/Texture_1.xpm", &width , &height );
	void *backg = mlx_xpm_file_to_image(ptr, "./Textures/bedrock.xpm", &width , &height );
	while(rdr->map[y])
	{
		x = 0;
		while(rdr->map[y][x])
		{
			if (rdr->map[y][x] == '1' || rdr->map[y][x] == '0')
				mlx_put_image_to_window(ptr , win , wall , x * 69 , y * 69);
			if (rdr->map[y][x] == '0')
				mlx_put_image_to_window(ptr , win , backg , x * 69 , y * 69);
			x++;
		}
		y++;
	}
	mlx_loop(ptr);
}

int y(t_mapinfo *x)
{
	int y = 0;
	while(x->map[y])
		y++;
	return y;
}

int main(int argc, char *argv[])
{
	t_mapinfo rdr;

	rdr = process_map(argv[1]);
	map_renderer(&rdr);
}
