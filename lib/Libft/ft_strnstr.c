/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:26:36 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/25 13:57:07 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t	i;
	size_t	j;
	char	*needle1;
	char	*haystack1;

	needle1 = (char *) needle;
	haystack1 = (char *) haystack;
	i = 0;
	if (needle[i] == '\0')
		return (haystack1);
	while (haystack1[i] != '\0' && i < len)
	{
		j = 0;
		while ((haystack1[i + j] == needle1[j] && (i + j) < len))
		{
			j++;
			if (needle1[j] == '\0')
				return (haystack1 + i);
		}
		i++;
	}
	return (NULL);
}
