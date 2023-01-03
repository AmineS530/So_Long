/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadik <asadik@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:10:10 by asadik            #+#    #+#             */
/*   Updated: 2022/10/26 14:52:28 by asadik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_strlen(char const *s, char c)
{
	int	owo;

	owo = 0;
	while (s[owo] != c && s[owo])
	{
		owo++;
	}
	return (owo);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static void	put_word(char const *s, char **tab, int wordpos, char c)
{
	int	j;
	int	pog;

	pog = wordpos;
	if (!tab[wordpos])
	{
		while (pog >= 0)
		{
			if (tab[pog] != NULL)
			{
				free(tab[pog]);
				tab[pog] = NULL;
			}
			pog--;
		}
		free (tab);
		tab = NULL;
	}
	j = 0;
	while (s[j] && s[j] != c)
	{
		tab[wordpos][j] = s[j];
		j++;
	}
	tab[wordpos][j] = '\0';
}

static void	put_split(char const *s, char **tab, char c, int pog)
{
	int	i;
	int	j;
	int	wordpos;

	i = 0;
	wordpos = 0;
	while (wordpos < pog && s[i])
	{
		j = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			tab[wordpos] = (char *)malloc((sizeof(char) * c_strlen(s + i, c)
						+ 1));
			put_word(s + i, tab, wordpos, c);
			i = c_strlen(s + i, c) + i;
			wordpos++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		pog;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	pog = word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (pog + 1));
	if (!tab)
		return (NULL);
	tab[pog] = NULL;
	put_split(s, tab, c, pog);
	return (tab);
}
