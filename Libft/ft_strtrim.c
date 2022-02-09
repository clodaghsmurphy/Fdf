/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:03:53 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/29 09:21:18 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	get_start(const char *s1, const char *set)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
			return (i);
		i++;
	}
	return (i);
}

static int	get_end(const char *s1, const char *set)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len && ft_strchr(set, s1[len - i - 1]) != 0)
	{
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(const char	*s1, const char	*set)
{
	char			*res;
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;

	start = get_start(s1, set);
	end = get_end(s1, set);
	len = end - start;
	if (start >= end)
		return (ft_strdup(""));
	if (set == 0)
		return (ft_strdup(s1));
	if (s1 == 0)
		return (NULL);
	res = malloc(sizeof(*res) * (len + 1));
	if (res == 0)
		return (NULL);
	ft_strlcpy(res, s1 + start, len + 1);
	return (res);
}
