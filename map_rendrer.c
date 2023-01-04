#include "so_long.h"

// int main()
// {

// 	t_mygame *x
// 	int i
// 	void *ptr = mlx_init();
// 	void *win = mlx_new_window(ptr,

// }




int y(t_mapinfo *x)
{
	int y = 0;
	while(x->map[y])
		y++;
	return y;
}

int main()
{
	t_mapinfo *x;
	printf("%d",y(x));
}
