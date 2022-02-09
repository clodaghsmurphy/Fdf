/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:05:48 by clmurphy          #+#    #+#             */
/*   Updated: 2021/11/30 17:37:53 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static int	nb_len(long long int nb)
{
	int			i;
	long int	n;

	n = (long) nb;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*make_array(long long int n, char *res, int len)
{
	while (n > 0)
	{
		res[len] = (n % 10) + 48;
		len--;
		n = n / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	long long int	nb;
	unsigned int	len;

	nb = n;
	len = nb_len(nb);
	res = malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (nb == 0)
		res[0] = 48;
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			res[0] = '-';
		}
		res = make_array (nb, res, (len - 1));
	}
	res[len] = '\0';
	return (res);
}
