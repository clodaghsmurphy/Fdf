/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:44:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/22 17:41:52 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_points_x(t_co *cords, t_fdf *fdf, int i, int j)
{
	cords->x1 = ((50 * (j + 1)) + (50 * (i + 1)) / 2);
	cords->y1 = ((50 * (i + 1)) - (50 * (j + 1)) / 4);
	cords->z1 = fdf->map.int_tab[i][j] * 5;
	cords->x2 = ((50 * (j + 2)) + (50 * (i + 1)) / 2);
	cords->y2 = ((50 * (i + 1)) - (50 * (j + 2)) / 4);
	cords->z2 = fdf->map.int_tab[i][j + 1] * 5;
	translate_point(fdf, cords, 400, 400);
	if (cords->x1 >= 0 && cords->y1 >= 0 && cords->x2 >= 0 && cords->y2 >= 0)
	{
		if (cords->x1 < WIN_WIDTH && cords->y1 < WIN_HEIGHT
			&& cords->x2 < WIN_WIDTH && cords->y2 < WIN_HEIGHT)
		{
			project(cords);
			ft_bresenham(cords, fdf);
		}
	}
	else
	{
		printf("too big 1 x is %d and y is %d\n", cords->x1, cords->y1);
		return ;
	}
}

void	set_points_y(t_co *cords, t_fdf *fdf, int i, int j)
{
	cords->x1 = ((50 * (j + 1)) + (50 * (i + 1)) / 2);
	cords->y1 = ((50 * (i + 1)) - (50 * (j + 1)) / 4);
	cords->z1 = fdf->map.int_tab[i][j] * 5;
	cords->x2 = ((50 * (j + 1)) + (50 * (i + 2)) / 2);
	cords->y2 = ((50 * (i + 2)) - (50 * (j + 1)) / 4);
	cords->z2 = fdf->map.int_tab[i + 1][j] * 5;
	translate_point(fdf, cords, 400, 400);
	if (cords->x1 >= 0 && cords->y1 >= 0 && cords->x2 >= 0 && cords->y2 >= 0)
	{
		if (cords->x1 < WIN_WIDTH && cords->y1 < WIN_HEIGHT
			&& cords->x2 < WIN_WIDTH && cords->y2 < WIN_HEIGHT)
		{
			project(cords);
			ft_bresenham(cords, fdf);
		}
	}
	else
	{
		printf("too big 2\n");
		return ;
	}
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
			printf("draw x 1 i is %d amd j is %d\n", i, j);
			set_points_x(cords, fdf, i, j);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < fdf->map.width - 1)
	{
		printf("draw x 2\n");
		set_points_x(cords, fdf, i, j);
		project(cords);
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
