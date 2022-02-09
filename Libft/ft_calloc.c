/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:43:43 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/28 15:57:09 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	void		*ptr;

	ptr = malloc(size * count);
	if (ptr == 0)
		return (NULL);
	ft_bzero (ptr, size * count);
	return (ptr);
}
