/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:52:38 by asadik            #+#    #+#             */
/*   Updated: 2023/01/11 13:22:34 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_walls(t_mapinfo *cords, int y, int x)
{
	if (cords->map[y][x] == '1')
		retrun (0);
	return (1);
}

t_mapinfo	*ft_movements_ver(t_mapinfo *cords, int dir)
{
	int	y;
	int x;

	y = cords->player_y;
	x = cords->player_x;
	if (check_for_walls(cords, y + dir , x))
	{
		cords->player_y += dir;
		cords->moves_counter++;
	}
	else if (check_for_walls(cords, y, (x + dir)))
	{
		cords->player_x += dir;
		cords->moves_counter++;
	}
	return (cords);
}

t_mapinfo	*ft_movements_hor(t_mapinfo *cords, int dir)
{
	int	y;
	int x;

	y = cords->player_y;
	x = cords->player_x;
	if (check_for_walls(cords, y, (x + dir)))
	{
		cords->player_x += dir;
		cords->moves_counter++;
	}
	return (cords);
}


t_mapinfo	*ft_input(t_mapinfo *cords, int keycode)
{
	if (keycode == 53)
		{
			mlx_destroy_window(cords->ptr, cords->win);
			ft_printf("%s You have closed teh game %s", RED, DEFAULT);
			exit(0);
		}
	if (keycode == 1)
		return (ft_movements_ver(game_map, 1));
	if (keycode == 13)
		return (ft_movements_ver(game_map, -1));
	if (keycode == 2)
		return (ft_movements_hor(game_map, 1));
	if (keycode == 0)
		return (ft_movements_hor(game_map, -1));
	return (game_map);
}
