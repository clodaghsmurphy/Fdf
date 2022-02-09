/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:40:59 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/24 14:42:43 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <unistd.h>
#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char	*dest, const char	*src, size_t	size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_i;
	size_t	res;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	dest_len = i;
	if (size < i + 1)
		return (size + j);
	else
		res = i + j;
	src_i = 0;
	while (((dest_len + src_i) < size - 1 && src[src_i] != '\0'))
	{
		dest[dest_len + src_i] = src[src_i];
		src_i++;
	}
	dest[i + src_i] = '\0';
	return (res);
}
