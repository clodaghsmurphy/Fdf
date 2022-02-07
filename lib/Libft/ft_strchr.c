/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:48:47 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/24 11:49:04 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	ltr;
	char			*str;

	str = (char *) s;
	ltr = (unsigned char) c;
	i = 0;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == ltr)
			return (str + i);
		i++;
	}
	return (NULL);
}
