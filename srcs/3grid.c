/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2grid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:04 by telee             #+#    #+#             */
/*   Updated: 2022/05/27 19:42:04 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	**grid_alloc(int row, int col)
{
	t_point	**tmp;
	int		i;

	tmp = malloc(sizeof(t_point *) * row);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < row)
		tmp[i++] = malloc(sizeof(t_point) * col);
	return (tmp);
}

void	grid_size(t_grid *grid, int row, int col)
{
	int	max_width;
	int	max_height;

	max_width = WIDTH / col;
	max_height = HEIGHT / row;
	if (max_width > max_height)
		grid->grid_size = max_width;
	else
		grid->grid_size = max_height;
}

void	grid_plot(char ***split, t_grid *grid)
{
	int		i;
	int		j;
	int		x;
	int		y;

	grid->grid = grid_alloc(grid->row, grid->col);
	grid->tmp_grid = grid_alloc(grid->row, grid->col);
	x = -(grid->grid_size * (grid->col - 1) / 2);
	y = (grid->grid_size * (grid->row - 1) / 2);
	i = -1;
	while (++i < grid->row)
	{
		j = -1;
		while (++j < grid->col)
		{
			grid->grid[i][j].x = x + (j * grid->grid_size);
			grid->grid[i][j].y = y - (i * grid->grid_size);
			grid->grid[i][j].z = -(ft_atoi(split[i][j])) * (grid->grid_size) * Z_ELVTD;
		}
	}
}

void	grid_dup(t_grid *grid)
{
	int	i;
	int	j;

	i = -1;
	while (++i < grid->row)
	{
		j = -1;
		while (++j < grid->col)
		{
			grid->tmp_grid[i][j].x = grid->grid[i][j].x;
			grid->tmp_grid[i][j].y = grid->grid[i][j].y;
			grid->tmp_grid[i][j].z = grid->grid[i][j].z;
		}
	}
}

void	grid_put(t_grid *grid, t_data *data, t_transform *transf)
{
	grid_dup(grid);
	transform(grid, transf);
	gridline_put(grid, data, 0x0000FF00);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}