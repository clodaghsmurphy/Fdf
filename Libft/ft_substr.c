/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:39:51 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/30 17:21:38 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;
	char	*s1;

	if (s == NULL)
		return (NULL);
	i = 0;
	s1 = (char *)s;
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (s1[start] && i < len)
	{
		new[i] = s1[start];
		start++;
		i++;
	}	
	new[i] = '\0';
	return (new);
}
