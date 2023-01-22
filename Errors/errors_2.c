/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:17:55 by asadik            #+#    #+#             */
/*   Updated: 2023/01/22 21:13:21 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	emptymap_err(void)
{
	ft_printf("%sError\nThe map is empty", RED);
	exit(6);
}

void	invalid_char_err(void)
{
	ft_printf("%sError\nMap contains invalid character", RED);
	exit(7);
}

void	invalid_border_err(void)
{
	ft_printf("%sError\nInvalid map border", RED);
	exit(8);
}

void	no_valid_path(void)
{
	ft_printf("%sError\nNo valid path in the map", RED);
	exit(8);
}

int	ft_exit(void)
{
	ft_printf("%sYou have pressed X to close the game%s", RED, DEFAULT);
	exit(0);
	return (0);
}
