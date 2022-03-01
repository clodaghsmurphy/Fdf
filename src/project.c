/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:59:09 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/01 16:16:58 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_point(t_fdf *fdf, t_co *cords)
{
	int	tx;
	int	ty;

	tx = fdf->trans_x;
	ty = fdf->trans_y;
	cords->x1 = cords->x1 + tx;
	cords->y1 = cords->y1 + ty;
	cords->x2 = cords->x2 + tx;
	cords->y2 = cords->y2 + ty;
}

void	translate_point2(t_fdf *fdf, t_co *cords)
{
	int	tx;
	int	ty;

	tx = fdf->trans_x;
	ty = fdf->trans_y;
	cords->x2 = cords->x2 + tx;
	cords->y2 = cords->y2 + ty;
}

void	project(t_co *cords, t_fdf *fdf)
{
	if (fdf->map.width < 200 || fdf->map.height < 200)
	{
		cords->z1 *= 3;
		cords->z2 *= 3;
	}
	cords->y1 = cords->y1 - cords->z1;
	cords->y2 = cords->y2 - cords->z2;
}

void	project2(t_co *cords, t_fdf *fdf)
{
	if (fdf->map.width < 200 || fdf->map.height < 200)
	{
		cords->z1 *= 3;
		cords->z2 *= 3;
	}
	cords->y2 = cords->y2 - cords->z2;
}

void	scale(t_fdf *fdf)
{
	int	zoom;

	if (fdf->map.height == 1)
		return ;
	zoom = (int)floor(hypot((double)fdf->map.height - 1,
				(double)fdf->map.width - 1));
	zoom = (int)zoom;
	zoom = WIN_HEIGHT / zoom;
	fdf->zoom = zoom;
	fdf->trans_x = WIN_WIDTH / 2;
	fdf->trans_y = WIN_HEIGHT / 4;
	if (fdf->map.height < 20)
		fdf->trans_y = WIN_HEIGHT / 7;
}
