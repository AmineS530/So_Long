/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:17:55 by asadik            #+#    #+#             */
/*   Updated: 2023/01/06 14:41:11 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	invalid_char_err(void)
{
	ft_printf("Map contains invalid character");
	exit(6);
}

void	invalid_border_err(void)
{
	ft_printf("Invalid map border");
	exit(7);
}
