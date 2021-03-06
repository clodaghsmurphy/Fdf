/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:11:30 by clmurphy          #+#    #+#             */
/*   Updated: 2022/03/01 17:13:00 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# include<stdio.h>
# include<math.h>
# include "../Libft/libft.h"
# include "fdf.h"

# define BUFFER_SIZE 42
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

typedef struct s_map
{
	int		width;
	int		height;
	char	***char_tab;
	int		**int_tab;

}	t_map;

typedef struct s_co
{
	int	x1;
	int	x2;
	int	z1;
	int	y1;
	int	y2;
	int	z2;

}	t_co;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	p;
	int	end;
	int	x;
	int	y;
	int	ym;
	int	xm;
	int	err;

}	t_line;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		zoom;
	int		colour;
	int		alt;
	int		trans_x;
	int		trans_y;
	t_map	map;
	t_data	img_str;

}	t_fdf;

typedef struct s_tab
{
	char			**tab;
	struct s_tab	*next;
}	t_tab;

void	check_list(t_tab **list, t_fdf *fdf);
int		is_num(char *str);
int		ft_isspace(char c);
/*---------------keycode------------------*/
int		ft_zoom(int keycode, t_fdf *fdf);
int		check_key(int keycode, t_fdf *fdf);
void	refresh_image(t_fdf *fdf);
void	printcords(t_co *cords);
void	print_one(t_fdf *fdf);
void	free_char_tab(char **tab);
void	free_tab(int **int_tab, t_fdf *fdf);
int		mouse_hook(int keycode, t_fdf *fdf);
int		ft_zoom(int keycode, t_fdf *fdf);
void	fdf_init(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
int		ft_close(t_fdf *fdf);
/*----------------draw------------------*/
void	last_line_y(t_fdf *fdf, t_co *cords, int i, int j);
void	last_line_x(t_fdf *fdf, t_co *cords, int i, int j);
void	ft_bresenham(t_co *cords, t_fdf *fdf);
void	draw(t_fdf *fdf);
void	set_points_x(t_co *cords, t_fdf *fdf, int i, int j);
void	set_points_y(t_co *cords, t_fdf *fdf, int i, int j);
void	draw_grid(t_fdf *fdf, t_co *cords);
/*---------------project------------------*/
void	translate_point(t_fdf *fdf, t_co *cords);
void	translate_point2(t_fdf *fdf, t_co *cords);
void	project(t_co *cords, t_fdf *fdf);
void	project2(t_co *cords, t_fdf *fdf );
void	set_data(t_co *cords, t_line *data);
void	ft_bresenham_bis(t_co *cords, t_fdf *fdf, t_line *data);
/*---------------Parse------------------*/
void	error(t_fdf *fdf);
void	check_shape(t_tab **list, t_fdf *fdf);
void	convert_int_tab(t_tab **list, t_fdf *fdf);
void	parse_map(int fd, t_fdf *fdf);
int		*ft_atoi_string(char **char_tab, t_fdf *fdf);
int		tab_width(char **tab);
void	printtab(int	**tab, t_fdf *fdf);
void	scale(t_fdf *fdf);
/*---------------list------------------*/
t_tab	*ft_my_lstnew(char **tab);
void	ft_my_lstadd_back(t_tab **alst, t_tab *new);
int		ft_my_lstsize(t_tab *lst);
void	ft_my_lstclear(t_tab **lst);
/*----------------GNL--------------------*/
char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, int c);

#endif