/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:18:27 by asadik            #+#    #+#             */
/*   Updated: 2023/01/04 12:41:28 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*ill need a tmp fd while i get the actual fd or actually open the map here*/
char	*ft_free(char *map, char *str)
{
	char *ayaya;

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
/* then put the joined map in a new 2D array and split it with \n to get literal map */
char	**ayaya_placeholder(char *map_name)
{
	int		fd;
	char	*str;
	char	*map;
	char	**fullmap;


	fd = open(name_checker(map_name), O_RDONLY);
	printf("%d", fd);
	while ((str = get_next_line(fd)))
	{
		map = ft_free(map, str);
		free (str);
	}
	fullmap = ft_split(map , '\n');
	free (map);
	return (fullmap);
}

 int main (int argc, char *argv[])
 {
	(void)argc;
	ayaya_placeholder(argv[1]);
	return (0);
 }
