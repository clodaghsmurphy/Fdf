/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:08:10 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/23 18:10:01 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;
	t_data	img;
	int		fd;

	if (ac < 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	fdf_init(&fdf);
	parse_map(fd, &fdf);
	img.img = mlx_new_image(fdf.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel,
			&img.line_length, &img.endian);
	fdf.img_str = img;
	draw(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr,
		fdf.img_str.img, 10, 10);
	mlx_hook(fdf.win_ptr, 2, 1L << 0, ft_close, &fdf);
	mlx_mouse_hook(fdf.win_ptr, mouse_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);
}

int	ft_close(int keycode, t_fdf *fdf)
{
	printf("keycode is %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int keycode, t_fdf *fdf)
{
	printf("keycode is %d\n", keycode);
	if (keycode == 4)
	{
		fdf->zoom = fdf->zoom * 2;
		mlx_do_sync(MLX_SYNC_WIN_FLUSH_CMD, fdf->win_ptr);
	}
	if (keycode == 4)
		fdf->zoom = fdf->zoom / 2;
	return (0);
}

int	ft_alt(int keycode, t_fdf *fdf)
{	
	fdf->alt = fdf->alt * 2;
	printf("keycode is %d\n", keycode);
	return (0);
}

void	fdf_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "window");
	fdf->zoom = 25;
	fdf->colour = 0x00FFFFFF;
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
	{
		printf("ERROR\n");
		return ;
	}
	dst = fdf->img_str.addr + (y * fdf->img_str.line_length
			+ x * (fdf->img_str.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
