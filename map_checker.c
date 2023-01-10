/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:33:18 by asadik            #+#    #+#             */
/*   Updated: 2023/01/10 15:58:25 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
 /* check border & check for valid path */

void	border_checker(t_mapinfo	*data)
{
	data->tmp = -1;
	data->y = 1;
	while (++data->tmp < data->line_count)
	{
		data->x = 0;
		if ((data->map[data->tmp][data->x] && data->tmp == 0 && data->x == 0) ||
			(data->map[data->tmp][data->x] && data->tmp + 1 == data->line_count && data->x == 0))
			check_firstnlast(data);
		if ((data->map[data->tmp][data->x] && data->tmp < data->line_count - 1 &&
			data->x == 0 )|| (data->map[data->tmp][data->x] &&
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
		else if ((data->map[data->y][0] != '1' || data->map[data->y][data->x] != '1'))
			invalid_border_err();
	}
}
