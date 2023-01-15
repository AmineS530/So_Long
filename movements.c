/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:52:38 by asadik            #+#    #+#             */
/*   Updated: 2023/01/16 00:38:59 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_walls(t_mapinfo *cords, int y, int x, int coin)
{
	if (cords->map[y][x] == '1' ||
		(cords->map[y][x] == 'E' && cords->collectables_count != coin))
			return (0);
	return (1);
}

int	ft_movements_ver(t_mapinfo *cords, int dir, int *score)
{
	int	y;

	y = cords->player_y;
	if (check_for_walls(cords, (y + dir) , cords->player_x, (*score)) == 1)
	{
		if (cords->map[y][cords->player_x] != 'E')
			cords->map[y][cords->player_x] = '0';
		cords->player_y += dir;
		if (cords->map[cords->player_y][cords->player_x] == 'C')
		{
			ft_printf("Ender eyes collected: %d / %d\n",
				++(*score), cords->collectables_count);
		}
		if (cords->map[cords->player_y][cords->player_x] != 'E')
			cords->map[cords->player_y][cords->player_x] = 'P';
		cords->moves_counter++;
		if (dir == -1)
			cords->player = cords->player_up;
		if (dir == 1)
			cords->player = cords->player_right;
		ft_printf("Number of movements: %d\n\n", cords->moves_counter);
	}
	return (cords->player_y);
}

int	ft_movements_hor(t_mapinfo *cords, int dir, int *score)
{
	int x;

	x = cords->player_x;
	if (check_for_walls(cords, cords->player_y, (x + dir), (*score)) == 1)
	{
		if (cords->map[cords->player_y][x] != 'E')
			cords->map[cords->player_y][cords->player_x] = '0';
		cords->player_x += dir;
		if (cords->map[cords->player_y][cords->player_x] == 'C')
		{
			ft_printf("Ender eyes collected: %d / %d\n",
				++(*score), cords->collectables_count);
		}
		if (cords->map[cords->player_y][cords->player_x] ==
			cords->map[cords->exit_y][cords->exit_x])
			cords->map[cords->player_y][cords->player_x] = 'E';
		else
		cords->map[cords->player_y][cords->player_x] = 'P';
		cords->moves_counter++;
		if (dir == 1)
			cords->player = cords->player_right;
		else if (dir == -1)
			cords->player = cords->player_left;
		ft_printf("Number of movements: %d\n\n", cords->moves_counter);
	}
	return (cords->player_x);
}


int	ft_input(int keycode, t_mapinfo *cords)
{
	static int	score;

	if (keycode == 126)
		ft_movements_ver(cords, -1, &score);
	else if (keycode == 125)
		ft_movements_ver(cords, 1, &score);
	else if (keycode == 123)
		ft_movements_hor(cords, -1, &score);
	else if (keycode == 124)
		ft_movements_hor(cords, 1, &score);
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
