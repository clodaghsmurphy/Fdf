/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:58:40 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/27 20:24:12 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	parse_map(int fd, t_fdf *fdf)
{
	char	*str;
	t_tab	*list;
	int		i;

	list = NULL;
	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_my_lstadd_back(&list, ft_my_lstnew(ft_split(str, ' ')));
		i++;
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	convert_int_tab(&list, fdf);
	scale(fdf);
}

void	check_shape(t_tab **list, t_fdf *fdf)
{
	int		flag;
	int		width;
	t_tab	*temp;

	flag = 0;
	if (*list == NULL)
	{
		error(fdf);
	}
	temp = *list;
	while (temp != NULL)
	{
		if (flag == 0)
		{
			width = tab_width((*list)->tab);
			flag = 1;
		}
		if (width != tab_width((*list)->tab))
			error(fdf);
		temp = temp->next;
	}
}

void	convert_int_tab(t_tab **list, t_fdf *fdf)
{
	t_tab		*temp;
	int			i;
	int			**int_tab;

	temp = *list;
	i = 0;
	fdf->map.width = tab_width((*list)->tab);
	fdf->map.height = ft_my_lstsize(*list);
	int_tab = malloc(sizeof(int *) * fdf->map.height);
	if (!int_tab)
		return ;
	while (temp != NULL)
	{
		int_tab[i] = ft_atoi_string(temp->tab, fdf);
		temp = temp->next;
		i++;
	}
	check_shape(list, fdf);
	ft_my_lstclear(list);
	fdf->map.int_tab = int_tab;
}

int	*ft_atoi_string(char **char_tab, t_fdf *fdf)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * fdf->map.width);
	if (!tab)
		return (0);
	while (char_tab[i])
	{
		tab[i] = ft_atoi(char_tab[i]);
		i++;
	}
	return (tab);
}

int	tab_width(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
