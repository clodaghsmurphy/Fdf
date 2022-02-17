/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:59:09 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/17 16:36:28 by clmurphy         ###   ########.fr       */
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

	printf("in rotate x1 is : %d\n and y1 is %d\n\n", cords->x1, cords->y1);
	x_shifted = cords->x1 - x_pivot;
	y_shifted = cords->y1 - y_pivot;
	cords->x1 = x_pivot + (x_shifted * cos(angle) - y_shifted * sin(angle));
	cords->y1 = x_pivot + (x_shifted * sin(angle) + y_shifted * sin(angle));
}

void	rotate2(t_co *cords, int x_pivot, int y_pivot, int angle)
{
	int	x_shifted;
	int	y_shifted;

	printf("in rotate\n");
	x_shifted = cords->x2 - x_pivot;
	y_shifted = cords->y2 - y_pivot;
	cords->x2 = x_pivot + (x_shifted * cos(angle) - y_shifted * sin(angle));
	cords->y2 = x_pivot + (x_shifted * sin(angle) + y_shifted * sin(angle));
}
