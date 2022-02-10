/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:11:30 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/10 13:29:46 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# include<stdio.h>
# include "../Libft/libft.h"

# define BUFFER_SIZE 2147483648

typedef struct s_map
{
	int		width;
	int		height;
	char	***char_tab;
	int		**int_tab;

}	t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*img_addr;
	t_map	*map;

}	t_fdf;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_tab
{
	char			**tab;
	struct s_tab	*next;
}	t_tab;

void	fdf_init(t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
/*---------------Parse------------------*/
int		tab_height(char **tab, t_fdf *fdf);
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