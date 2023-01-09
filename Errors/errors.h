/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:45:39 by asadik            #+#    #+#             */
/*   Updated: 2023/01/09 14:47:23 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include "../so_long.h"

/* errors1 */
void	invalid_name_err(void);
void	nomap_err(void);
void	map_border_err(void);
void	invalid_shape_err(void);
void	invalid_settings_err(void);
/* errors2 */
void	emptymap_err(void);
void	invalid_char_err(void);
void	invalid_border_err(void);

#endif
