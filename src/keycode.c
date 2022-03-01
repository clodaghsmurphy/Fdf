/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:05:52 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/01 15:50:27 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	check_key(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		ft_close(fdf);
    
	return (0);
}

int	ft_zoom(int keycode, t_fdf *fdf)
{
	printf("keycode is %d\n", keycode);
	if (keycode == 4)
	{
		//fdf->zoom = fdf->zoom * 2;
		refresh_image(fdf);
	}
	if (keycode == 5)
	{
		//fdf->zoom = fdf->zoom / 2;
		refresh_image(fdf);
	}
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

void    refresh_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_str.img);
    fdf->img_str.img = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    draw(fdf); 
    fdf->img_str.addr = mlx_get_data_addr(fdf->img_str.img,
			fdf->img_str.bits_per_pixel,
			fdf->img_str.line_length, fdf->img_str.endian);
    mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->img_str.img, 10, 10);
}
                                                                             