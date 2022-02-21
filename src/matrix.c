/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:59:09 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/21 17:18:14 by clmurphy         ###   ########.fr       */
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

void	rotate(t_co *cords, int x_pivot, int y_pivot, int angle)
{
	int	x_shifted;
	int	y_shifted;

	x_shifted = cords->x1 - x_pivot;
	y_shifted = cords->y1 - y_pivot;
	cords->x1 = x_pivot + (x_shifted * COS(angle) - y_shifted * SIN(angle));
	cords->y1 = x_pivot + (x_shifted * COS(angle) + y_shifted * SIN(angle));
}

void	rotate2(t_co *cords, int x_pivot, int y_pivot, int angle)
{
	int	x_shifted;
	int	y_shifted;

	x_shifted = cords->x2 - x_pivot;
	y_shifted = cords->y2 - y_pivot;
	cords->x2 = x_pivot + (x_shifted * COS(angle) - y_shifted * SIN(angle));
	cords->y2 = x_pivot + (x_shifted * SIN(angle) + y_shifted * SIN(angle));
}

void	project(t_co *cords)
{
	cords->y1 = cords->y1 - cords->z1;
//	cords->x1 = cords->x1 - cords->z1;
	cords->y2 = cords->y2 - cords->z2;
//	cords->x2 = cords->x2 - cords->z2;
//	cords->x1 = (cords->x1 - cords->y1) * cos(0.463646716);
//	cords->y1 = (cords->x1 + cords->y1) * sin(0.463646716) - cords->z1;
}
