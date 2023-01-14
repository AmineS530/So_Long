/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:52:38 by asadik            #+#    #+#             */
/*   Updated: 2023/01/14 17:48:29 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_walls(t_mapinfo *cords, int y, int x)
{
	if (cords->map[y][x] == '1')
		return (0);
	return (1);
}

int	ft_movements_ver(t_mapinfo *cords, int dir)
{
	int	y;
	int x;

	y = cords->player_y;
	x = cords->player_x;
	if (check_for_walls(cords, (y + dir) , x))
	{
		mlx_destroy_image(cords->ptr, cords->player);
		cords->map[cords->player_y][cords->player_x] = '0';
		cords->player_y += dir;
		cords->map[cords->player_y][cords->player_x] = 'P';
		cords->moves_counter++;
		render_objs(cords);
	}
	printf("%s", cords->map[cords->y]);
	return (cords->player_y);
}

int	ft_movements_hor(t_mapinfo *cords, int dir)
{
	int	y;
	int x;

	y = cords->player_y;
	x = cords->player_x;
	if (check_for_walls(cords, y, (x + dir)))
	{
		cords->map[cords->player_y][cords->player_x] = '0';
		cords->player_x += dir;
		cords->map[cords->player_y][cords->player_x] = 'P';
		cords->moves_counter++;
	}
	return (cords->player_x);
}


int	ft_input(int keycode, t_mapinfo *cords)
{

	if (keycode == 1)
		return (ft_movements_ver(cords, 1));
	else if (keycode == 13)
		return (ft_movements_ver(cords, -1));
	else if (keycode == 2)
		return (ft_movements_hor(cords, 1));
	else if (keycode == 0)
		return (ft_movements_hor(cords, -1));
	else if (keycode == 53)
	{
		mlx_destroy_window(cords->ptr, cords->win);
		ft_printf("%s You have closed the game %s", RED, DEFAULT);
		exit(0);
	}
	return (0);
}
