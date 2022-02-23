/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:44:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/23 17:25:16 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_points_x(t_co *cords, t_fdf *fdf, int i, int j)
{
	cords->x1 = ((fdf->zoom * (j + 1)) + (fdf->zoom * (i + 1)) / 3);
	cords->y1 = ((fdf->zoom * (i + 1)) - (fdf->zoom * (j + 1)) / 4);
	cords->z1 = fdf->map.int_tab[i][j];
	cords->x2 = ((fdf->zoom * (j + 2)) + (fdf->zoom * (i + 1)) / 3);
	cords->y2 = ((fdf->zoom * (i + 1)) - (fdf->zoom * (j + 2)) / 4);
	cords->z2 = fdf->map.int_tab[i][j + 1];
	translate_point(fdf, cords, 200, 300);
	project(cords, fdf);
	ft_bresenham(cords, fdf);
}

void	set_points_y(t_co *cords, t_fdf *fdf, int i, int j)
{
	cords->x1 = ((fdf->zoom * (j + 1)) + (fdf->zoom * (i + 1)) / 3);
	cords->y1 = ((fdf->zoom * (i + 1)) - (fdf->zoom * (j + 1)) / 4);
	cords->z1 = fdf->map.int_tab[i][j];
	cords->x2 = ((fdf->zoom * (j + 1)) + (fdf->zoom * (i + 2)) / 3);
	cords->y2 = ((fdf->zoom * (i + 2)) - (fdf->zoom * (j + 1)) / 4);
	cords->z2 = fdf->map.int_tab[i + 1][j];
	translate_point(fdf, cords, 200, 300);
	project(cords, fdf);
	ft_bresenham(cords, fdf);
}

void	draw(t_fdf *fdf)
{
	t_co	cords;

	draw_x(fdf, &cords);
	draw_y(fdf, &cords);
}

void	draw_x(t_fdf *fdf, t_co *cords)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.height - 1)
	{
		j = 0;
		while (j < fdf->map.width - 1)
		{
			set_points_x(cords, fdf, i, j);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < fdf->map.width - 1)
	{
		set_points_x(cords, fdf, i, j);
		project(cords, fdf);
		ft_bresenham(cords, fdf);
		j++;
	}
}

void	draw_y(t_fdf *fdf, t_co *cords)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.width - 1)
	{
		j = 0;
		while (j < fdf->map.height - 1)
		{
			set_points_y(cords, fdf, j, i);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < fdf->map.height - 1)
	{
		set_points_y(cords, fdf, j, i);
		j++;
	}
}
