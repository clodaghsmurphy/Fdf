/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:41:42 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/22 14:08:32 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<ctype.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*int	main(int ac, char **av)
{
printf("-------- FT_ISDIGIT -------------\n");
	printf("my function : %d\n", ft_isdigit('7'));
	printf("real function : %d\n\n", isdigit('7'));
}*/
