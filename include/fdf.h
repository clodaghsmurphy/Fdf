/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:11:30 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/09 17:19:48 by clmurphy         ###   ########.fr       */
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
	int	width;
	int	length;

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

void	fdf_init(t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*----------------GNL--------------------*/
char	*get_next_line(int fd);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s, int c);

#endif