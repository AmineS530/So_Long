/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:35:05 by asadik            #+#    #+#             */
/*   Updated: 2023/02/23 19:39:17 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	invalid_name_err(void)
{
	ft_printf("%sError\nInvalid map name", RED);
	exit(1);
}

void	nomap_err(void)
{
	ft_printf("%sError\nMap doesn't exist", RED);
	exit(2);
}

void	map_border_err(void)
{
	ft_printf("%sError\nmap border isn't aligned", RED);
	exit(3);
}

void	newlines_in_map(void)
{
	ft_printf("%sError\nMap contain newlines", RED);
	exit(4);
}

void	invalid_settings_err(void)
{
	ft_printf("%sError\nInvalid map settings", RED);
	exit(5);
}
