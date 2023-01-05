/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:18:27 by asadik            #+#    #+#             */
/*   Updated: 2023/01/05 14:27:06 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*ill need a tmp fd while i get the actual fd or actually open the map here*/
char	*name_checker(char *map_name)
{
	size_t	len;
	char	*ber;

	len = ft_strlen(map_name);
	if (len < 4)
		invalid_name_err();
	ber = ft_strrchr(map_name, '.');
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
	while (str != NULL)
	{
		map = ft_strjoin(map, str);
		free (str);
		str = get_next_line(fd);
	}
	fullmap = ft_split(map, '\n');
	close(fd);
	free (map);
	return (fullmap);
}

/* Player-Collectable-Exit-Shape_checker */
void	pces_checker(t_mapinfo *pces)
{
	pces->res = ft_strlen(pces->map[pces->y]);
	while (pces->map[pces->y])
	{
		pces->x = 0;
		while (pces->map[pces->y][pces->x])
		{
			if (pces->res != ft_strlen(pces->map[pces->y]))
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
	if (pces->res <= pces->y)
		invalid_shape_err();
	if (pces->player_count != 1 || pces->collectables_count < 1
		|| pces->exit_count != 1)
		invalid_settings_err();
}
/* mc = Map Check*/

t_mapinfo	process_map(char *map_name)
{
	t_mapinfo	mc;

	mc.y = 0;
	mc.x = 0;
	mc.map = read_map(map_name);
	mc.player_count = 0;
	mc.collectables_count = 0;
	mc.exit_count = 0;
	pces_checker(&mc);
	return (mc);
}

int main(int argc, char *argv[])
{
	t_mapinfo test;

	if (argc == 2)
	{
		test = process_map(argv[1]);
		ft_printf("%d\n", test.collectables_count);
		ft_printf("%d\n", test.player_count);
		ft_printf("%d\n", test.exit_count);
	}
	return (0);
}
