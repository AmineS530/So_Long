/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:38:56 by asadik            #+#    #+#             */
/*   Updated: 2023/01/16 04:07:14 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "Utils/libft/get_next_line.h"
# include "Utils/libft/libft.h"
# include "Utils/ft_printf/ft_printf.h"
# include"Errors/errors.h"
# define RES 69
# define RED "\e[31m"
# define YELLOW "\e[33m"
# define GREEN "\e[32m"
# define CYAN "\e[36m"
# define DEFAULT "\033[0m"
# define TRUE 1
#define FALSE 0
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
	int					game_over;
	int					won;
/* graphic related vars */
	int					height;
	int					width;
	void				*ptr;
	void				*win;
	void				*wall;
	void				*coin;
	void				*backg;
	void				*exit_open;
	void				*exit;
	void				*player;
	void				*player_up;
	void				*player_right;
	void				*player_left;
	void				*win_screen;
	int					player_x;
	int					player_y;
	int					exit_x;
	int					exit_y;
	int					moves_counter;
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
void			set_cords(t_mapinfo *xy);

/* map_renderer */
void			render_objs(t_mapinfo *objs);
t_mapinfo		map_renderer(t_mapinfo rdr);
void			ft_put_xpm(t_mapinfo *files);
int				game_over(t_mapinfo *game);

/* movements */
int				check_for_walls(t_mapinfo *crd, int y, int x, int coin);
int				cgs(t_mapinfo *crd, int *score, int x, int y);
int				ft_movements_ver(t_mapinfo *crd, int dir, int *coins_counter);
int				ft_movements_hor(t_mapinfo *crd, int dir, int *coins_counter);
int				ft_input(int keycode, t_mapinfo *crd);

#endif
