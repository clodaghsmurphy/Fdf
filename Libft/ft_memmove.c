/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:29:38 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/29 12:01:50 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

void	*ft_memmove(void	*str1, const void *str2, size_t	n)
{
	char			*src;
	char			*dest;

	dest = (char *) str1;
	src = (char *) str2;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n--)
			dest[n] = src[n];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
