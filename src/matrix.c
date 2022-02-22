/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:59:09 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/22 17:50:33 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_point(t_fdf *fdf, t_co *cords, int tx, int ty)
{
	(void)fdf;
	cords->x1 = cords->x1 + tx;
	cords->y1 = cords->y1 + ty;
	cords->x2 = cords->x2 + tx;
	cords->y2 = cords->y2 + ty;
}

void	project(t_co *cords)
{
	cords->y1 = cords->y1 - cords->z1;
	cords->y2 = cords->y2 - cords->z2;
}

void	ft_bresenham(t_co *cords, t_fdf *fdf)
{
	t_line	data;

	set_data(cords, &data);
	if (data.dx > data.dy)
	{
		data.err = data.dx / 2;
		while (data.x != cords->x2)
		{
			printf("in bres x is %d and x2 is %d\n", data.x, cords->x2);
			if (data.x == 1750)
				sleep(1);
			if (cords->x1 >= 0 && cords->y1 >= 0
				&& cords->x2 >= 0 && cords->y2 >= 0)
			{
				if (cords->x1 < WIN_WIDTH && cords->y1 < WIN_HEIGHT
					&& cords->x2 < WIN_WIDTH && cords->y2 < WIN_HEIGHT)
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
				return ;
		}
	}
	else
		ft_bresenham_bis(cords, fdf, &data);
	my_mlx_pixel_put(fdf, data.x, data.y, 0x00FF0000);
}

void	set_data(t_co *cords, t_line *data)
{
	data->dx = abs(cords->x2 - cords->x1);
	data->dy = abs(cords->y2 - cords->y1);
	data->x = cords->x1;
	data->y = cords->y1;
	if (cords->x1 > cords->x2)
		data->xm = -1;
	else
		data->xm = 1;
	if (cords->y1 > cords->y2)
		data->ym = -1;
	else
		data->ym = 1;
}

void	ft_bresenham_bis(t_co *cords, t_fdf *fdf, t_line *data)
{
	data->err = data->dy / 2;
	while (data->y != cords->y2)
	{
		if (cords->x1 >= 0 && cords->y1 >= 0
			&& cords->x2 >= 0 && cords->y2 >= 0)
		{
			if (cords->x1 < WIN_WIDTH && cords->y1 < WIN_HEIGHT
				&& cords->x2 < WIN_WIDTH && cords->y2 < WIN_HEIGHT)
			{	
				my_mlx_pixel_put(fdf, data->x, data->y, 0x00FF0000);
				data->err -= data->dx;
				if (data->err < 0)
				{
					data->x += data->xm;
					data->err += data->dy;
				}
			}
		}
		else
			return ;
		data->y += data->ym;
	}
}
