/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:37:22 by asadik            #+#    #+#             */
/*   Updated: 2023/01/11 11:32:32 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mapinfo	rdr;

	if (argc == 2)
	{
		rdr = process_map(argv[1]);
		map_renderer(rdr);
		while (1)
		{}
	}
	else
		ft_printf("I quote \"%sYou didn't include a map, YOU DUCK%s\",%s Yuki%s",
			YELLOW, DEFAULT, CYAN, DEFAULT);
	return (0);
}
