/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:38:56 by asadik            #+#    #+#             */
/*   Updated: 2023/01/05 15:28:03 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "Utils/libft/get_next_line.h"
# include "Utils/libft/libft.h"
# include "Utils/ft_printf/ft_printf.h"
# include"Errors/errors.h"
typedef struct s_map_data
{
	int		y;
	int		x;
	char	**map;
	int		player_count;
	int		exit_count;
	int		collectables_count;
	int		res;
	void	*ptr;
}			t_mapinfo;

/* map_reader */

char	*name_checker(char *map_name);
char	**read_map(char *map_name);
void	characters_checker(t_mapinfo *chr);
void	pces_counter(t_mapinfo *pces);
t_mapinfo	process_map(char *map_name);



#endif
