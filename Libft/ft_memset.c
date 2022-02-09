/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:17:05 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/23 12:48:24 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void	*ft_memset(void	*s, int c, size_t n)
{
	size_t			i;
	unsigned char	replace;
	unsigned char	*str;

	replace = (unsigned char) c;
	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = replace;
		i ++;
	}
	return (str);
}	
