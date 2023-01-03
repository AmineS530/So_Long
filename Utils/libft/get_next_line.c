/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:33:53 by asadik            #+#    #+#             */
/*   Updated: 2023/01/03 13:49:41 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_list
{
	char	*buffer;
	char	*s1;
	char	*nextline;
	int		bytes_read;
	int		i;
	int		owo;
}			t_gnlkit;

char	*ft_substr_free(char *s, unsigned int start, size_t len, int freesub)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (++i < len)
	{
		sub[i] = s[i + start];
	}
	if (freesub == 42069)
		free (s);
	*(sub + i) = '\0';
	return (sub);
}

char	*ft_find_line(char *alpha)
{
	t_gnlkit	n_line;

	n_line.i = 0;
	if (!alpha[n_line.i])
		return (NULL);
	while (alpha[n_line.i] != '\0' && alpha[n_line.i] != '\n')
		n_line.i++;
	n_line.nextline = ft_substr(alpha, 0, n_line.i + 1, 0);
	return (n_line.nextline);
}

char	*ft_set_remainder(char *alpha)
{
	t_gnlkit	n_line;

	n_line.i = 0;
	while (alpha[n_line.i])
	{
		if (alpha[n_line.i] == '\n')
			break ;
		n_line.i++;
	}
	n_line.i++;
	if (!alpha[n_line.i])
	{
		free(alpha);
		return (0);
	}
	n_line.owo = 0;
	while (alpha[n_line.i + n_line.owo] != '\0')
		n_line.owo++;
	alpha = ft_substr(alpha, n_line.i, n_line.owo + n_line.i + 1, 42069);
	return (alpha);
}

char	*ft_read_from_fd(int fd, char *alpha)
{
	t_gnlkit	read_fd;

	if (!alpha)
		alpha = ft_strdup("");
	read_fd.buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	read_fd.bytes_read = 42069;
	while (read_fd.bytes_read != 0)
	{
		read_fd.bytes_read = read(fd, read_fd.buffer, BUFFER_SIZE);
		if (read_fd.bytes_read == -1)
		{
			free(alpha);
			free(read_fd.buffer);
			return (NULL);
		}
		read_fd.buffer[read_fd.bytes_read] = '\0';
		alpha = ft_strjoin(alpha, read_fd.buffer);
		if (ft_strchr(alpha, '\n'))
			break ;
	}
	free(read_fd.buffer);
	return (alpha);
}

char	*get_next_line(int fd)
{
	static char	*alpha;
	t_gnlkit	beta;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	alpha = ft_read_from_fd(fd, alpha);
	if (!alpha)
		return (0);
	beta.nextline = ft_find_line(alpha);
	alpha = ft_set_remainder(alpha);
	return (beta.nextline);
}
