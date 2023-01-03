/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:34:58 by asadik            #+#    #+#             */
/*   Updated: 2023/01/03 13:49:29 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_substr_free(char *s, unsigned int start, size_t len, int freesub);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*read_from_fd(int fd, char *alpha);
char	*ft_find_line(char *alpha);
char	*ft_set_remainder(char *alpha);

#endif
