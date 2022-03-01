/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:47:25 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/01 17:24:00 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	print_one(t_fdf *fdf)
{
	my_mlx_pixel_put(fdf, 800, 500, fdf->colour);
}

void	error(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	//mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	exit(0);
}

void	free_tab(int **int_tab, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map.height)
	{
		free(int_tab[i]);
		i++;
	}
	free(int_tab);
}

void	free_char_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	check_list(t_tab **list, t_fdf *fdf)
{
	t_tab	*temp;
	int		i;
	int		flag;
	int		width;

	i = 0;
	flag = 0;
	temp = *list;
	while (temp->next != NULL)
	{	
		i = 0;
		while (temp->tab[i])
		{
			if (!ft_isdigit(temp->tab[i][0]))
			{
				ft_my_lstclear(list);
				error(fdf);
			}
			i++;
		}
		if (flag == 0)
		{
			width = i;
			flag = 1;
		}
		if (i != width)
		{
			ft_my_lstclear(list);
			error(fdf);
		}
		temp = temp->next;
	}
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
/*
void	printcords(t_co *cords)
{
	printf("\n-----------------------------\n");
	printf("X1 : %d\n", cords->x1);
	printf("Y1 : %d\n", cords->y1);
	printf("X2 : %d\n", cords->x2);
	printf("Y2 : %d\n", cords->y2);
	printf("\n-----------------------------\n");
}*/
