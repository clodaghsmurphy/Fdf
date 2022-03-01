/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:44:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/01 14:37:28 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_points_x(t_co *cords, t_fdf *fdf, int i, int j)
{
	int	tile_half;
	int	mapx;
	int	mapy;

	mapx = j + 1;
	mapy = i + 1;
	tile_half = fdf->zoom;
	cords->x1 = (mapx - mapy) * tile_half;
	cords->y1 = ((mapx + mapy) * tile_half) / 2;
	cords->z1 = fdf->map.int_tab[i][j];
	cords->x2 = ((mapx + 1) - mapy) * tile_half ;
	cords->y2 = (((mapx + 1) + mapy) * tile_half) / 2;
	cords->z2 = fdf->map.int_tab[i][j + 1];
	project(cords);
	translate_point(fdf, cords);
	ft_bresenham(cords, fdf);
	cords->x2 = (mapx - (mapy + 1)) * tile_half;
	cords->y2 = ((mapx + (mapy + 1)) * tile_half) / 2;
	cords->z2 = fdf->map.int_tab[i + 1][j];
	project2(cords);
	translate_point2(fdf, cords);
	ft_bresenham(cords, fdf);
}

void	draw(t_fdf *fdf)
{
	t_co	cords;
	int		i;
	int		j;

	i = fdf->map.height - 1;
	j = fdf->map.width -1;
	if (fdf->map.height == 1)
	{
		print_one(fdf);
		return ;
	}
	draw_grid(fdf, &cords);
	last_line_y(fdf, &cords, i, j);
	last_line_x(fdf, &cords, i, j);
}

void	last_line_y(t_fdf *fdf, t_co *cords, int i, int j)
{
	int	mapx;
	int	mapy;
	int	tile_half;

	mapx = fdf->map.width;
	mapy = 1;
	i = 0;
	tile_half = fdf->zoom;
	while (mapy < fdf->map.height)
	{
		cords->x1 = (mapx - mapy) * tile_half;
		cords->y1 = ((mapx + mapy) * tile_half) / 2;
		cords->z1 = fdf->map.int_tab[i][j];
		cords->x2 = (mapx - (mapy + 1)) * tile_half ;
		cords->y2 = ((mapx + (mapy + 1)) * tile_half) / 2;
		cords->z2 = fdf->map.int_tab[i + 1][j];
		translate_point(fdf, cords);
		project(cords);
		ft_bresenham(cords, fdf);
		mapy++;
		i++;
	}
}

void	last_line_x(t_fdf *fdf, t_co *cords, int i, int j)
{
	int	mapx;
	int	mapy;
	int	tile_half;

	mapx = 1;
	mapy = fdf->map.height;
	j = 0;
	tile_half = fdf->zoom;
	while (mapx < fdf->map.width)
	{
		cords->x1 = (mapx - mapy) * tile_half;
		cords->y1 = ((mapx + mapy) * tile_half) / 2;
		cords->z1 = fdf->map.int_tab[i][j];
		cords->x2 = ((mapx + 1) - mapy) * tile_half;
		cords->y2 = ((mapx + 1) + mapy) * tile_half / 2;
		cords->z2 = fdf->map.int_tab[i][j + 1];
		translate_point(fdf, cords);
		project(cords);
		ft_bresenham(cords, fdf);
		mapx++;
		j++;
	}
}

void	draw_grid(t_fdf *fdf, t_co *cords)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.height - 2)
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
		j++;
	}
}
