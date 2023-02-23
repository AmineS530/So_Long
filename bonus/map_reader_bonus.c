/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:12:50 by asadik            #+#    #+#             */
/*   Updated: 2023/02/23 19:42:29 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*ill need a tmp fd while i get the actual fd or actually open the map here*/
char	*name_checker(char *map_name)
{
	size_t	len;
	char	*ber;

	ber = ft_strrchr(map_name, '.');
	if (ber == NULL)
		invalid_name_err();
	len = ft_strlen(ber);
	if (len < 4)
		invalid_name_err();
	if (ft_strncmp(ber, ".ber", 4) == 0)
		return (map_name);
	return (NULL);
}

/* get the .ber map and make it one string/2D map */
/* then put the joined map in a new 2D array and
			 split it with \n to get literal map */
char	**read_map(char *map_name)
{
	int		fd;
	char	*str;
	char	*map;
	char	**fullmap;

	map = ft_strdup("");
	fd = open(name_checker(map_name), O_RDONLY);
	if (fd < 0)
		nomap_err();
	str = get_next_line(fd);
	if (str == NULL)
		emptymap_err();
	while (str != NULL)
	{
		map = ft_strjoin(map, str);
		if (*str == '\n')
			newlines_in_map();
		str = get_next_line(fd);
	}
	free(str);
	fullmap = ft_split(map, '\n');
	close(fd);
	free (map);
	return (fullmap);
}

void	characters_checker(t_mapinfo *chr)
{
	chr->y = 0;
	while (chr->map[chr->y])
	{
		chr->x = 0;
		while (chr->map[chr->y][chr->x])
		{
			if (chr->map[chr->y][chr->x] == '0' ||
				chr->map[chr->y][chr->x] == '1' ||
				chr->map[chr->y][chr->x] == 'P' ||
				chr->map[chr->y][chr->x] == 'E' ||
				chr->map[chr->y][chr->x] == 'C')
					chr->x++;
			else if (chr->map[chr->y][chr->x] == 'F')
			{
				chr->e_count++;
					chr->x++;
			}
			else
				invalid_char_err();
		}
		chr->y++;
	}
	chr->line_count = chr->y;
}

/* Player-Collectable-Exit_counter */
void	pces_counter(t_mapinfo *pces)
{
	pces->y = 0;
	pces->res = ft_strlen(pces->map[pces->y]);
	while (pces->map[pces->y])
	{
		pces->x = 0;
		while (pces->map[pces->y][pces->x])
		{
			if (pces->res != (int)ft_strlen(pces->map[pces->y]))
				map_border_err();
			if (pces->map[pces->y][pces->x] == 'P')
				pces->player_count++;
			if (pces->map[pces->y][pces->x] == 'C')
				pces->collectables_count++;
			if (pces->map[pces->y][pces->x] == 'E')
				pces->exit_count++;
			pces->x++;
		}
		pces->y++;
	}
	if (pces->player_count != 1 || pces->collectables_count < 1
		|| pces->exit_count != 1)
		invalid_settings_err();
}
/* mc = Map Check*/

t_mapinfo	process_map(char	*map_name)
{
	t_mapinfo	mc;

	mc.y = 0;
	mc.x = 0;
	mc.tmp = 0;
	mc.map = read_map(map_name);
	mc.pathmap = read_map(map_name);
	mc.player_count = 0;
	mc.collectables_count = 0;
	mc.exit_count = 0;
	mc.e_count = 0;
	mc.won = FALSE;
	mc.game_over = FALSE;
	characters_checker(&mc);
	pces_counter(&mc);
	border_checker(&mc);
	set_cords(&mc);
	if ((check_path(&mc, mc.player_y, mc.player_x)) != 1)
		no_valid_path();
	return (mc);
}
