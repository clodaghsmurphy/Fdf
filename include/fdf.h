/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:11:30 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/21 18:07:58 by clmurphy         ###   ########.fr       */
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

# define BUFFER_SIZE 2147483648
# define SIN(x) sin(x * 3.141592653589 / 180)
# define COS(x) cos(x * 3.141592653589 / 180)

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
	t_map	map;
	t_data	img_str;

}	t_fdf;

typedef struct s_tab
{
	char			**tab;
	struct s_tab	*next;
}	t_tab;

void	fdf_init(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
int		ft_close(int keycode, t_fdf *fdf);
/*----------------draw------------------*/
void	ft_bresenham(t_co *cords, t_fdf *fdf);
void	draw(t_fdf *fdf);
void	set_data(t_line *data, t_co *cords);
void	ft_bresenham_low(int x1, int y1, int x2, int y2, t_fdf *fdf);
void	ft_bresenham_high(int x1, int y1, int x2, int y2, t_fdf *fdf);
void	set_points(t_co *cords, t_fdf *fdf, int i, int j);
/*---------------matrix------------------*/
void	translate_point(t_fdf *fdf, t_co *cords, int tx, int ty);
void	rotate(t_co *cords, int x_pivot, int y_pivot, int angle);
void	rotate2(t_co *cords, int x_pivot, int y_pivot, int angle);
void	project(t_co *cords);
/*---------------Parse------------------*/
void	convert_int_tab(t_tab **list, t_fdf *fdf);
void	parse_map(int fd, t_fdf *fdf);
int		*ft_atoi_string(char **char_tab, t_fdf *fdf);
int		tab_width(char **tab, t_fdf *fdf);
void	printtab(int	**tab, t_fdf *fdf);

t_tab	*ft_my_lstnew(char **tab);
void	ft_my_lstadd_back(t_tab **alst, t_tab *new);
int		ft_my_lstsize(t_tab *lst);
/*----------------GNL--------------------*/
char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, int c);

#endif