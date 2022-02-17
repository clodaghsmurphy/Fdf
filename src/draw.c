/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:44:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/17 16:54:28 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *fdf)
{
	int		i;
	int		j;
	t_co	cords;

	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			cords.x1 = (25 * (j + 1));
			cords.y1 = (25 * (i + 1));
			cords.z1 = fdf->map.int_tab[i][j];
			cords.x2 = (25 * (j + 2));
			cords.y2 = (25 * (i + 1));
			cords.z2 = fdf->map.int_tab[i][j];
			translate_point(fdf, &cords, 200, 200);
			rotate(&cords, 400, 400, 45);
			rotate2(&cords, 400, 400, 45);
			ft_bresenham(&cords, fdf);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < fdf->map.width)
	{
	cords.x1 = (25 * (j + 1));
			cords.y1 = (25 * (i + 1));
			cords.x2 = (25 * (j + 2));
			cords.y2 = (25 * (i + 1));
			translate_point(fdf, &cords, 200, 200);
			rotate(&cords, 400, 400, 45);
			rotate2(&cords, 400, 400, 45);

			ft_bresenham(&cords, fdf);
		j++;
	}
		
	i = 0;
	while (i < fdf->map.width)
	{
		j = 0;
		while (j < fdf->map.height)
		{
			cords.x1 = (25 * (i + 1));
			cords.y1 = (25 * (j + 1));
			cords.z1 = fdf->map.int_tab[j][i];
			cords.x2 = (25 * (i + 1));
			cords.y2 = (25 * (j + 2));
			cords.z2 = fdf->map.int_tab[j][i];
			translate_point(fdf, &cords, 200, 200);
			rotate(&cords, 400, 400, 45);
			rotate2(&cords, 400, 400, 45);
			ft_bresenham(&cords, fdf);
			j++;
		}
		i++;
	}
	j= 0;
	while (j < fdf->map.height)
		{
			cords.x1 = (25 * (i + 1));
			cords.y1 = (25 * (j + 1));
			cords.x2 = (25 * (i + 1));
			cords.y2 = (25 * (j + 2));
			translate_point(fdf, &cords, 200, 200);
			rotate(&cords, 400, 400, 45);
			rotate2(&cords, 400, 400, 45);
			ft_bresenham(&cords, fdf);
			j++;
		}
}

void	ft_bresenham(t_co *cords, t_fdf *fdf)
{
	t_line	data;

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


/*
void	ft_bresenham(t_co *cords, t_fdf *fdf)
{
	if (abs(cords->y2 - cords->y1) < abs(cords->x2 - cords->x1))
	{
		if (cords->x1 > cords->x2)
			ft_bresenham_low(cords->x2, cords->y2, cords->x1, cords->y1, fdf);
		else
			ft_bresenham_low(cords->x1, cords->y1, cords->x2, cords->y2, fdf);
	}
	else
	{
		if (cords->y1 > cords->y2)
			ft_bresenham_high(cords->x1, cords->y1, cords->x2, cords->y2, fdf);
		else
			ft_bresenham_high(cords->x2, cords->y2, cords->x1, cords->y1, fdf);
	}
}

void	ft_bresenham(t_co *cords, t_fdf *fdf)
{
	data.dx = abs(x2 - x1);
	data.dy = abs(y2 - y1);
	data.xm = -1;
	data.ym = -1;

	if (data.dy < 0)
	{
		data.ym = -1;
		data.dy = -data.dy;
	}
	if (data.dx < 0)
	{
		data.xm = -1;
		data.dx = -data.dx;
	}

}


void	ft_bresenham_low(int x1, int y1, int x2, int y2, t_fdf *fdf)
{
	printf("in low\n");
	t_line	data;

	data.end = x1 - x2;
	data.dx = abs(x2 - x1);
	data.dy = abs(y2 - y1);
	data.ym = 1;
	if (data.dy < 0)
	{
		data.ym = -1;
		data.dy = -data.dy;
	}
	data.p = 2 * data.dy - data.dx;
	data.x = x1;
	data.y = y1;
	while (data.x != x2 && data.y != y2)
	{
		my_mlx_pixel_put(fdf, data.x, data.y, 0x00FF0000);
		if (data.p >= 0)
		{
			data.y = data.y + data.ym;
			data.p = 2 * data.dy - data.dx;
		}
		else
			data.p = data.p + 2 * data.dy;
	}
}

void	ft_bresenham_high(int x1, int y1, int x2, int y2, t_fdf *fdf)
{
	t_line	data;

	data.y = y1;
	data.end = y1 - y2;
	data.dx = abs(x2 - x1);
	data.dy = abs(y2 - y1);
	data.xm = 1;
	if (data.dx < 0)
	{
		data.xm = -1;
		data.dx = -data.dx;
	}
	data.p = (2 * data.dx) - data.dx;
	data.x = x1;
	data.y = ;
	printf("in high y and y is %d and y1 is %d\n", data.y, y2);
	while (data.y < y1 - y2)
	{
		//printf("in high y and y is %d and y1 is %d\n", data.y, y2);
		printf("data.x is %x and data.y is %d\n", data.x, data.y);
		my_mlx_pixel_put(fdf, data.x, data.y, 0x00FF0000);
		if (data.p > 0)
		{
			data.x = data.x + data.xm;
			data.p = 2 * (data.dx - data.dy);
		}
		else
			data.p = data.p + 2 * data.dy;
	}
}
*/