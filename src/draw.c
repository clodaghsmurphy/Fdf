/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:44:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/22 11:56:10 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_points(t_co *cords, t_fdf *fdf, int i, int j)
{
	cords->x1 = ((50 * (j + 1)) + (50 * (i + 1)) / 2);
	cords->y1 = ((50 * (i + 1)) - (50 * (j + 1)) / 4);
	cords->z1 = fdf->map.int_tab[i][j];
	cords->x2 = ((50 * (j + 2)) + (50 * (i + 1)) / 2);
	cords->y2 = ((50 * (i + 1)) - (50 * (j + 2)) / 4);
	cords->z2 = fdf->map.int_tab[i][j + 1];
	translate_point(fdf, cords, 400, 400);
	project(cords);
	ft_bresenham(cords, fdf);
}

void	set_points2(t_co *cords, t_fdf *fdf, int i, int j)
{
	cords->x1 = ((50 * (j + 1)) + (50 * (i + 1)) / 2);
	cords->y1 = ((50 * (i + 1)) - (50 * (j + 1)) / 4);
	cords->z1 = fdf->map.int_tab[i][j];
	cords->x2 = ((50 * (j + 1)) + (50 * (i + 2)) / 2);
	cords->y2 = ((50 * (i + 2)) - (50 * (j + 1)) / 4);
	cords->z2 = fdf->map.int_tab[i + 1][j];
	translate_point(fdf, cords, 400, 400);
	project(cords);
	ft_bresenham(cords, fdf);
}

void	draw(t_fdf *fdf)
{
	int		i;
	int		j;
	t_co	cords;

	i = 0;
	while (i < fdf->map.height - 1)
	{
		j = 0;
		while (j < fdf->map.width - 1)
		{
			set_points(&cords, fdf, i, j);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < fdf->map.width - 1)
	{
		set_points(&cords, fdf, i, j);
		project(&cords);
		ft_bresenham(&cords, fdf);
		j++;
	}
	i = 0;
	while (i < fdf->map.width - 1)
	{
		j = 0;
		while (j < fdf->map.height - 1)
		{
			set_points2(&cords, fdf, j, i);
			project(&cords);
			ft_bresenham(&cords, fdf);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < fdf->map.height - 1)
	{
		set_points2(&cords, fdf, j, i);
		project(&cords);
		ft_bresenham(&cords, fdf);
		j++;
	}
}

void	ft_bresenham(t_co *cords, t_fdf *fdf)
{
	t_line	data;

	printf(" (%d, %d) to (%d, %d)\n", cords->x1, cords->y1, cords->x2, cords->y2);
	data.dx = abs(cords->x2 - cords->x1);
	data.dy = abs(cords->y2 - cords->y1);
	data.x = cords->x1;
	data.y = cords->y1;
	if (cords->x1 > cords->x2)
		data.xm = -1;
	else
		data.xm = 1;
	if (cords->y1 > cords->y2)
		data.ym = -1;
	else
		data.ym = 1;
	if (data.dx > data.dy)
	{
		data.err = data.dx / 2;
		while (data.x != cords->x2)
		{
			my_mlx_pixel_put(fdf, data.x, data.y, 0x00FF0000);
			data.err -= data.dy;
			if (data.err < 0)
			{
				data.y += data.ym;
				data.err += data.dx;
			}
			data.x += data.xm;
		}
	}
	else
	{
		data.err = data.dy / 2;
		while (data.y != cords->y2)
		{
			my_mlx_pixel_put(fdf, data.x, data.y, 0x00FF0000);
			data.err -= data.dx;
			if (data.err < 0)
			{
				data.x += data.xm;
				data.err += data.dy;
			}
			data.y += data.ym;
		}
	}
	my_mlx_pixel_put(fdf, data.x, data.y, 0x00FF0000);
}
