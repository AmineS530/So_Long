/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:18:27 by asadik            #+#    #+#             */
/*   Updated: 2023/01/04 14:21:41 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*ill need a tmp fd while i get the actual fd or actually open the map here*/
char	*ft_free(char *map, char *str)
{
	char	*ayaya;

	ayaya = ft_strjoin(map, str);
	free (str);
	return (ayaya);
}

char	*name_checker(char *map_name)
{
	size_t	len;
	char	*ber;

	len = ft_strlen(map_name);
	if (len < 4)
	{
		ft_printf("Invalid map name");
		exit(0);
	}
	ber = ft_strrchr(map_name, '.');
	if (ft_strncmp(ber, ".ber",4) == 0)
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
	{
		ft_printf("Map doesn't exist");
		exit(1);
	}
	while ((str = get_next_line(fd)))
		map = ft_free(map, str);
	fullmap = ft_split(map , '\n');
	close(fd);
	free (map);
	return (fullmap);
}

/* Player-Collectable-Exit_checker */
void	pce_checker(t_mapinfo ayaya)
{
	while (ayaya.map[ayaya.y])
	{
		if (ft_strchr(ayaya.map[ayaya.y],'P'))
			ayaya.player_count++;
		if (ft_strchr(ayaya.map[ayaya.y],'C'))
			ayaya.collectables_count++;
		if (ft_strchr(ayaya.map[ayaya.y],'E'))
			ayaya.exit_count++;
		ayaya.y++;
	}
	if (ayaya.player_count != 1 || ayaya.collectables_count < 1 || ayaya.exit_count != 1)
	{
		ft_printf("Invalid map settings");
		exit(3);
	}
}
/* mc = Map Check*/
t_mapinfo	*process_map(char *map_name)
{
	t_mapinfo	mc;

	mc.y = 0;
	mc.x = 0;
	mc.map = read_map(map_name);
	mc.player_count = 0;
	mc.collectables_count = 0;
	mc.exit_count = 0;
	pce_checker(mc);
	return(mc);
}
