/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:22:09 by telee             #+#    #+#             */
/*   Updated: 2022/05/31 15:25:26 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define HEIGHT     720
# define WIDTH      1280
# define Z_ELVTD	0.3
# define ON_DESTROY	17

# include <stdio.h>

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct s_transform
{
	t_point	rotate;
	float	zoom;
	float	iso_radian_const;
}				t_transform;

typedef struct s_grid
{
	t_point	**grid;
	t_point	**tmp_grid;
	int		col;
	int		row;
	int		grid_size;
}				t_grid;

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
void		init_window(t_data *data, char *title);
int			init_grid(t_grid *grid, char *file);
void		init_transform(t_transform *transf);
void		gridline_put(t_grid *grid, t_data *data, int color);
void		grid_put(t_grid *grid, t_data *data, t_transform *transf);
void		grid_dup(t_grid *grid);
int			grid_build(int fd, t_grid *grid);
char		***create_array(t_list *lst, int row);
t_list		*get_list(int fd, int *row);
char		***free_array(char ***split, int row);
void		grid_plot(char ***split, t_grid *grid);
t_point		**grid_alloc(int row, int col);
void		grid_size(t_grid *grid, int row, int col);
int			check_array(char ***split, int row, int *col);
t_point		**grid_alloc(int row, int col);
t_point		**free_grid(t_point **grid, int row);

void		isometric(t_point *coor, float iso_rad_const);
t_matrix	rotate_x(int degree);
t_matrix	rotate_y(int degree);
t_matrix	rotate_z(int degree);
void		rotate(t_point *coor, char axis, int degree);
void		zoom(t_point *coor, float zoom);
void		center(t_point *coor);
void		transform(t_grid *grid, t_transform *tform);

int			exit_win(t_data *data);
int			key_hook(int keycode, t_data *data);

#endif