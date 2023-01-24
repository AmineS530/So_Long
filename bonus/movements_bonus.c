/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:52:38 by asadik            #+#    #+#             */
/*   Updated: 2023/01/24 10:56:26 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_for_walls(t_mapinfo *crd, int y, int x, int coin)
{
	if (crd->map[y][x] == '1' ||
		(crd->map[y][x] == 'E' && crd->collectables_count != coin)
		|| crd->game_over)
		return (0);
	return (1);
}

int	cgs(t_mapinfo *crd, int *score, int y, int x)
{
	if (crd->map[y][x] == crd->map[crd->exit_y][crd->exit_x]
		&& (*score) == crd->collectables_count)
	{
		crd->won = TRUE;
		crd->game_over = TRUE;
		game_over(crd);
		return (0);
	}
	return (1);
}

int	ft_movements_ver(t_mapinfo *crd, int dir, int *score)
{
	int	y;

	y = crd->player_y;
	if (check_for_walls(crd, (y + dir), crd->player_x, (*score))
		&& cgs(crd, score, y, crd->player_x))
	{
		if (crd->map[y][crd->player_x] != 'E')
			crd->map[y][crd->player_x] = '0';
		crd->player_y += dir;
		if (crd->map[crd->player_y][crd->player_x] == 'F')
			crd->game_over = TRUE;
		if (crd->map[crd->player_y][crd->player_x] == 'C')
			ft_printf("Ender eggs collected:%s %d / %d\n%s", YELLOW,
				++(*score), crd->collectables_count, DEFAULT);
		if (crd->map[crd->player_y][crd->player_x] != 'E')
			crd->map[crd->player_y][crd->player_x] = 'P';
		crd->moves_counter++;
		if (dir == -1)
			crd->player = crd->player_up;
		if (dir == 1)
			crd->player = crd->player_right;
	}
	return (cgs(crd, score, crd->player_y, crd->player_x));
}

int	ft_movements_hor(t_mapinfo *crd, int dir, int *score)
{
	int	x;

	x = crd->player_x;
	if (check_for_walls(crd, crd->player_y, (x + dir), (*score))
		&& cgs(crd, score, crd->player_y, x))
	{
		if (crd->map[crd->player_y][x] != 'E')
			crd->map[crd->player_y][crd->player_x] = '0';
				crd->player_x += dir;
		if (crd->map[crd->player_y][crd->player_x] == 'F')
			crd->game_over = TRUE;
		if (crd->map[crd->player_y][crd->player_x] == 'C')
			ft_printf("Ender eggs collected:%s %d / %d\n%s", YELLOW,
				++(*score), crd->collectables_count, DEFAULT);
		if (crd->exit_y == crd->player_y && crd->exit_x == crd->player_x)
			crd->map[crd->player_y][crd->player_x] = 'E';
		else
		crd->map[crd->player_y][crd->player_x] = 'P';
		crd->moves_counter++;
		if (dir == 1)
			crd->player = crd->player_right;
		else if (dir == -1)
			crd->player = crd->player_left;
	}
	return (cgs(crd, score, crd->player_y, crd->player_x));
}

int	ft_input(int keycode, t_mapinfo *crd)
{
	static int	score;

	crd->display_move = ft_itoa(crd->moves_counter);
	if (keycode == 126 || keycode == 13)
		ft_movements_ver(crd, -1, &score);
	else if (keycode == 125 || keycode == 1)
		ft_movements_ver(crd, 1, &score);
	else if (keycode == 123 || keycode == 0)
		ft_movements_hor(crd, -1, &score);
	else if (keycode == 124 || keycode == 2)
		ft_movements_hor(crd, 1, &score);
	else if (keycode == 53)
		ft_close_window(crd->ptr, crd->win);
	if (crd->collectables_count == score)
		crd->exit = crd->exit_open;
	else
		cgs(crd, &score, crd->player_y, crd->player_x);
	mlx_clear_window(crd->ptr, crd->win);
	render_objs(crd);
	mlx_string_put(crd->ptr, crd->win, (crd->res / 2) * RES, 10, 0x00FFFFFF,
		crd->display_move);
	free (crd->display_move);
	return (game_over(crd));
}
