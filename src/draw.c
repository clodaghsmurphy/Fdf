/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:44:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/15 17:16:22 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *fdf)
{
	int		i;
	int		j;
	t_co	cords;

	i = 0;
	while (i < fdf->map.height - 1)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			cords.x1 = fdf->map.int_tab[i][j] + (25 * (i + 1));
			cords.y1 = fdf->map.int_tab[i][j] + (25 * (j + 1));
			cords.x2 = fdf->map.int_tab[i][j] + (25 * (i + 2));
			cords.y2 = fdf->map.int_tab[i][j] + (25 * (j + 2));
			ft_bresenham(&cords, fdf);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < fdf->map.height - 2)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			cords.x1 = fdf->map.int_tab[i][j] + (25 * (i + 1));
			cords.y1 = fdf->map.int_tab[i][j] + (25 * (j + 1));
			cords.x2 = fdf->map.int_tab[i][j] + (25 * (i + 1));
			cords.y2 = fdf->map.int_tab[i][j] + (25 * (j + 2));
			ft_bresenham(&cords, fdf);
			j++;
		}
		i++;
	}
}

void	ft_bresenham(t_co *cords, t_fdf *fdf)
{
	t_line	data;

	set_data(&data, cords);
	my_mlx_pixel_put(fdf, data.x, data.y, 0x00FF0000);
	while (data.x <= data.end)
	{
		printf("p is %d and end is %d\n", data.p, data.end);
		printf("x is %d and y is %d\n", data.x, data.y);
		if (data.p < 0)
		{
			data.x = data.x + 1;
			data.p = data.p + 2 * data.dy;
		}
		else
		{
			data.x = data.x + 1;
			data.y = data.y + 1;
			data.p = data.p + 2 * (data.dy - data.dx);
		}
		my_mlx_pixel_put(fdf, data.x, data.y, 0x00FF0000);
	}
}

void	set_data(t_line *data, t_co *cords)
{
	data->dx = abs(cords->x2 - cords->x1);
	data->dx = abs(cords->y2 - cords->y1);
	data->p = 2 * data->dy - data->dx;
	if (cords->x1 > cords->x2)
	{
		data->x = cords->x2;
		data->y = cords->y2;
		data->end = cords->x2;
	}
	else
	{
		data->x = cords->x1;
		data->y = cords->y1;
		data->end = cords->x2;
	}
}
