/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:22:09 by telee             #+#    #+#             */
/*   Updated: 2022/05/30 09:19:22 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define HEIGHT     480
# define WIDTH      640
# define MENU_WIDTH 250
# define FT_UINT_MAX    ((unsigned)(~0L))
# define FT_INT_MAX ((int)(FT_UINT_MAX >> 1))
# define FT_INT_MIN ((int)(~FT_INT_MAX))
# define WIN_FIT    0.80

# include <stdio.h>

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct s_trans
{
	int	x;
	int	y;
}				t_trans;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	int	width;
	int	height;
	int	*point_arr;
	int	*color_arr;
	int	z_min;
	int	z_max;
	int	z_range;
}				t_map;

typedef struct s_grid
{
	t_point	**grid;
	t_point	**tmp_grid;
	int		col;
	int		row;
	int		box_length;
}				t_grid;

typedef struct s_transform
{
	t_point	rotate;
	t_trans	transform;
	float	zoom;
	int		projection;
	double	z0_const;
	float	iso_radian_const;
}				t_transform;

typedef struct s_matrix
{
	float	a;
	float	b;
	float	c;
	float	d;
	float	e;
	float	f;
	float	g;
	float	h;
	float	i;
}				t_matrix;

void		pixel_put(t_data *data, int x, int y, int color);
void		line_put(t_point a, t_point b, int color, t_data *data);
int			abs_int(int n);
float		abs_float(float n);
void		init_window(t_data *data, char *title);
int			init_grid(t_grid *grid, char *file);
void		init_transform(t_transform *transf);
void		gridline_put(t_grid *grid, t_data *data, int color);
void		grid_put(t_grid *grid, t_data *data, t_transform *transf);
void		blank_put(t_data *data);
void		grid_dup(t_grid *grid);
int			read_file(int fd, t_grid *grid);
char		***create_array(t_list *lst, int row);
t_list		*create_list(int fd, int *row);
char		***free_array(char ***split, int row);
t_point		**grid_plot(char ***split, t_grid *grid);
t_point		**grid_alloc(int row, int col);
void		grid_wireframe(t_grid *grid, int row, int col);
int			check_array(char ***split, int row, int *col);
t_point		**grid_alloc(int row, int col);
t_point		**grid_free(t_point **grid, int row);
void		clean_image(t_data *data);

void		perspective(t_point *coor, double Z0);
void		isometric(t_point *coor, float iso_rad_const);
void		switch_projection(int *projection);
t_matrix	rotate_x(int degree);
t_matrix	rotate_y(int degree);
t_matrix	rotate_z(int degree);
void		rotate(t_point *coor, char axis, int degree);
void		zoom(t_point *coor, float zoom);
void		translate(t_point *coor, t_trans trans);
void		center(t_point *coor);
void		transform(t_grid *grid, t_transform *tform);

void		exit_hook(t_data *data);
void		key_hook2(int keycode, t_data *data);
int			key_hook(int keycode, t_data *data);

#endif