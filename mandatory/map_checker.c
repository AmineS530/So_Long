/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:33:18 by asadik            #+#    #+#             */
/*   Updated: 2023/02/06 19:39:48 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/* check border & check for valid path */

void	border_checker(t_mapinfo	*data)
{
	data->tmp = -1;
	data->y = 1;
	while (++data->tmp < data->line_count)
	{
		data->x = 0;
		if ((data->map[data->tmp][data->x] && data->tmp == 0 && data->x == 0) ||
			(data->map[data->tmp][data->x] && data->tmp + 1 == data->line_count
			&& data->x == 0))
			check_firstnlast(data);
		if ((data->map[data->tmp][data->x] && data->tmp < data->line_count - 1
			&& data->x == 0) || (data->map[data->tmp][data->x] &&
				data->tmp < data->line_count - 1 && data->x == data->res))
			check_sides(data);
	}
}

void	check_firstnlast(t_mapinfo *data)
{
	while (data->x <= data->res && data->map[data->tmp][data->x])
	{
		if (data->map[data->tmp][data->x] == '1' )
			data->x++;
		else
			invalid_border_err();
	}
}

void	check_sides(t_mapinfo *data)
{
	while (data->y < data->line_count - 1 && data->map[data->y][data->x])
	{
		data->x = data->res - 1;
		if (data->map[data->y][0] == '1' && data->map[data->y][data->x] == '1')
			data->y++;
		else if ((data->map[data->y][0] != '1'
			|| data->map[data->y][data->x] != '1'))
			invalid_border_err();
	}
}

void	set_cords(t_mapinfo *xy)
{
	xy->y = 0;
	while (xy->map[xy->y])
	{
		xy->x = 0;
		while (xy->map[xy->y][xy->x])
		{
			if (xy->map[xy->y][xy->x] == 'P')
			{
				xy->player_x = xy->x;
				xy->player_y = xy->y;
			}
			if (xy->map[xy->y][xy->x] == 'E')
			{
				xy->exit_x = xy->x;
				xy->exit_y = xy->y;
			}
			xy->x++;
		}
		xy->y++;
	}
}

int	check_path(t_mapinfo *path, int y, int x)
{
	static int	i;

	if (path->pathmap [y][x] == 'C')
		i++;
	if (i == path->collectables_count
		&& y == path->exit_y && x == path->exit_x)
		return (1);
	if (path->pathmap [y][x] == '7' || path->pathmap [y][x] == '1')
		return (0);
	path->pathmap [y][x] = '7';
	return (check_path(path, y, x + 1) || check_path(path, y + 1, x)
		|| check_path(path, y, x - 1) || check_path(path, y - 1, x));
}
