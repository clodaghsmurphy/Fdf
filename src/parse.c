/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:58:40 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/10 13:37:26 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/fdf.h"

void	parse_map(int fd, t_fdf *fdf)
{
	char	*str;
	t_tab	*list;
	int		i;

	list = NULL;
	i = 0;
	(void) fdf;
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
}

void	convert_int_tab(t_tab **list, t_fdf *fdf)
{
	t_tab		*temp;
	int			i;
	int			**int_tab;

	temp = *list;
	i = 0;
	tab_width((*list)->tab, fdf);
	fdf->map->height = ft_my_lstsize(*list);
	int_tab = malloc(sizeof(int *) * fdf->map->height);
	if (!int_tab)
		return ;
	while (temp->next != NULL)
	{
		int_tab[i] = ft_atoi_string(temp->tab, fdf);
		temp = temp->next;
		i++;
	}
	fdf->map->int_tab = int_tab;
	printtab(fdf->map->int_tab, fdf);
}

void	printtab(int	**tab, t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < fdf->map->height - 1)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			j++;
		}
		i++;
	}
}

int	*ft_atoi_string(char **char_tab, t_fdf *fdf)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * fdf->map->width);
	if (!tab)
		return (0);
	while (char_tab[i])
	{
		tab[i] = ft_atoi(char_tab[i]);
		i++;
	}
	(void) fdf;
	return (tab);
}

int	tab_width(char **tab, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	fdf->map->width = i;
	return (i);
}
