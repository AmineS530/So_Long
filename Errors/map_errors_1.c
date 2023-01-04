/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:35:05 by asadik            #+#    #+#             */
/*   Updated: 2023/01/04 18:46:39 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "../Utils/ft_printf/ft_printf.h"

void	invalid_name_err(void)
{
	ft_printf("Invalid map name");
	exit(1);
}

void	nomap_err(void)
{
	ft_printf("Map doesn't exist");
	exit(2);
}

void	map_border_err(void)
{
	ft_printf("map border isn't aligned");
	exit(3);
}

void	invalid_shape_err(void)
{
	ft_printf("Invalid map shape, maps should be rectangular");
	exit(4);
}

void	invalid_settings_err(void)
{
	ft_printf("Invalid map settings");
	exit(5);
}
