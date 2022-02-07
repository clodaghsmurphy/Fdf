/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:49:54 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/28 16:49:55 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 1;
	if (lst == 0)
		return (0);
	while (lst ->next != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
