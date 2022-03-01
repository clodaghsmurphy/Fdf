/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:05:52 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/01 16:13:21 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_key(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		ft_close(fdf);
	return (0);
}

int	ft_close(t_fdf *fdf)
{
	free_tab(fdf->map.int_tab, fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_str.img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	exit(0);
	return (0);
}
