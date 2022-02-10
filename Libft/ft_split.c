/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:03:22 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/10 12:10:28 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

static char	**error(char	**tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	count_words(const char *str, const char c)
{
	unsigned int	word;
	unsigned int	i;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
		{
			i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
		if (str[i] == c || str[i] == '\0')
			word++;
	}
	return (word);
}

static char	**word_length(const char *s, char c, char **tab, int words)
{
	unsigned int	i;
	unsigned int	j;
	int				word;

	i = 0;
	word = 0;
	j = 0;
	while (word < words)
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		tab[word] = malloc(sizeof(char *) * j + 1);
		if (tab[word] == NULL)
			return (error(tab));
		ft_strlcpy(tab[word], s + i, j + 1);
		i = i + j;
		word++;
	}
	tab[word] = NULL;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char				**tab;
	unsigned int		words;

	words = count_words(s, c);
	tab = malloc(sizeof(char **) * (words + 1));
	if (tab == 0)
		return (NULL);
	tab = word_length(s, c, tab, words);
	return (tab);
}
