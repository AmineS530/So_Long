/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:18:27 by asadik            #+#    #+#             */
/*   Updated: 2023/01/03 20:55:52 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*ill need a tmp fd while i get the actual fd or actually open the map here*/

/* get the .ber map and make it one string/2D map */

while ((str = get_next_line(fd)))
    {
        map = ft_strjoin(map, str);
        free (str);
    }
return (map)
/* then put the joined map in a new 2D array and split it with \n to get literal map */

char **fullmap = ft_split(map , '\n');
