/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:33:18 by asadik            #+#    #+#             */
/*   Updated: 2023/01/06 17:42:55 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
 /* check border & check for valid path */

void	border_checker(t_mapinfo	*data)
{
	data->tmp = -1;
	ft_printf("line count %d \n", data->line_count);
	data->y = 1;
	while (++data->tmp < data->line_count)
	{
		data->x = 0;
		if ((data->map[data->tmp][data->x] && data->tmp == 0 && data->x == 0) ||
			(data->map[data->tmp][data->x] && data->tmp + 1 == data->line_count && data->x == 0))
		{
			while (data->x <= data->res && data->map[data->tmp][data->x])
			{
				if (data->map[data->tmp][data->x] == '1' )
					data->x++;
				else
					invalid_border_err();
			}
		}
		if ((data->map[data->tmp][data->x] && data->tmp < data->line_count - 1 &&
			data->x == 0 )|| (data->map[data->tmp][data->x] &&
				data->tmp < data->line_count - 1 && data->x == data->res))
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
	}
}
