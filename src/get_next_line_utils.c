/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:22:16 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/14 09:02:53 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

char	*ft_strdup_gnl(const char	*s1)
{
	unsigned int	i;
	char			*dup;

	if (!s1)
		return (NULL);
	dup = malloc(sizeof(dup) * (ft_strlen(s1) + 1));
	if (dup == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
		if (dup[i - 1] == '\n')
			break ;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strchr_gnl(char *str, int c)
{
	size_t			i;
	unsigned char	ltr;

	if (!str)
		return (0);
	ltr = (unsigned char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ltr)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!str1)
		str1 = ft_strdup_gnl("\0");
	if (!str2)
		return (NULL);
	j = 0;
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (str == 0)
		return (NULL);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{	
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(str1), str);
}
