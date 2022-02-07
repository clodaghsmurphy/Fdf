/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:01:28 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/28 16:01:37 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			ltr;
	char			*str;
	unsigned int	i;

	ltr = (char) c;
	str = (char *) s;
	i = ft_strlen(str) + 1;
	while (i > 0)
	{
		i--;
		if (str[i] == ltr)
			return (str + i);
	}
	return (NULL);
}
