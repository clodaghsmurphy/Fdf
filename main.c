/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:08:10 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/07 15:02:15 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mlx/mlx.h"
#include"fdf.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "window");

	mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF);
	mlx_string_put(mlx_ptr, win_ptr, 110, 100, 0xFFFFFF, "my first pixel");
	image = mlx_new_image(mlx_ptr, 10, 20);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image, 150, 200);
	mlx_loop(mlx_ptr);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
