/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:27:05 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/24 14:27:06 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ltr;
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	ltr = (unsigned char) c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (ltr == str[i])
			return (str + i);
		i++;
	}
	return (NULL);
}
