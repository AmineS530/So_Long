/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:52:38 by asadik            #+#    #+#             */
/*   Updated: 2023/01/15 22:30:30 by asadik           ###   ########.fr       */
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
	if (check_for_walls(cords, (y + dir) , x) == 1)
	{
		cords->map[cords->player_y][cords->player_x] = '0';
		cords->player_y += dir;
		cords->map[cords->player_y][cords->player_x] = 'P';
		cords->moves_counter++;
		if (dir == -1)
			cords->player = cords->player_up;
		else if (dir == 1)
			cords->player = cords->player_right;
	}
	return (cords->player_y);
}

int	ft_movements_hor(t_mapinfo *cords, int dir)
{
	int	y;
	int x;

	y = cords->player_y;
	x = cords->player_x;
	if (check_for_walls(cords, y, (x + dir)) == 1)
	{
		cords->map[cords->player_y][cords->player_x] = '0';
		cords->player_x += dir;
		cords->map[cords->player_y][cords->player_x] = 'P';
		cords->moves_counter++;
		if (dir == 1)
			cords->player = cords->player_right;
		else if (dir == -1)
			cords->player = cords->player_left;
	}
	return (cords->player_x);
}


int	ft_input(int keycode, t_mapinfo *cords)
{
	if (keycode == 126)
		ft_movements_ver(cords, -1);
	else if (keycode == 125)
		ft_movements_ver(cords, 1);
	else if (keycode == 123)
		ft_movements_hor(cords, -1);
	else if (keycode == 124)
		ft_movements_hor(cords, 1);
	else if (keycode == 53)
	{
		mlx_destroy_window(cords->ptr, cords->win);
		ft_printf("%s You have closed the game %s", RED, DEFAULT);
		exit(0);
	}
	mlx_clear_window(cords->ptr, cords->win);
	render_objs(cords);
	return (0);
}
