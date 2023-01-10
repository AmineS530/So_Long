/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:38:56 by asadik            #+#    #+#             */
/*   Updated: 2023/01/10 16:23:37 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "Utils/libft/get_next_line.h"
# include "Utils/libft/libft.h"
# include "Utils/ft_printf/ft_printf.h"
# include"Errors/errors.h"
# define RED "\e[31m"
# define YELLOW "\e[33m"
# define GREEN "\e[32m"
# define CYAN "\e[36m"
# define DEFAULT "\033[0m"

typedef struct s_map_data
{
	int					y;
	int					x;
	char				**map;
	int					player_count;
	int					exit_count;
	int					collectables_count;
	int					res;
	int					line_count;
	int					tmp;
/* graphic related vars */
	int					height;
	int					width;
	void				*ptr;
	void				*win;
	void				*wall;
	void				*player;
	void				*coin;
	void				*backg;
	struct s_map_data	*next_frame;
}						t_mapinfo;

/* map_reader */
char			*name_checker(char *map_name);
char			**read_map(char *map_name);
void			characters_checker(t_mapinfo *chr);
void			pces_counter(t_mapinfo *pces);
t_mapinfo		process_map(char *map_name);

/* map_checker */
void			border_checker(t_mapinfo	*data);
void			check_firstnlast(t_mapinfo *data);
void			check_sides(t_mapinfo *data);

/* map_renderer */
void			render_objs(t_mapinfo *objs);
t_mapinfo		*map_renderer(t_mapinfo rdr);
t_mapinfo		*free_frame(t_mapinfo *info);

#endif
