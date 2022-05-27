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

#include "fdf.h"

t_point	**grid_alloc(int row, int col)
{
	t_point	**tmp;
	int		i;

	tmp = malloc(sizeof(t_point *) * row);
	i = 0;
	while (i < row)
		tmp[i++] = malloc(sizeof(t_point) * col);
	return (tmp);
}

t_point	**grid_plot(char ***split, t_grid *grid)
{
	int		i;
	int		j;
	int		x;
	int		y;
	t_point	**tmp;

	if (!split)
		return (NULL);
	tmp = grid_alloc(grid->row, grid->col);
	i = -1;
	x = -(grid->box_length * (grid->col - 1) / 2);
	y = (grid->box_length * (grid->row - 1) / 2);
	while (++i < grid->row)
	{
		j = -1;
		while (++j < grid->col)
		{
			tmp[i][j].x = x + (j * grid->box_length);
			tmp[i][j].y = y - (i * grid->box_length);
			tmp[i][j].z = -(ft_atoi(split[i][j])) * (grid->box_length) * 0.1;
		}
	}
	return (tmp);
}

void	grid_temp(t_grid *grid, int row, int col)
{
	int	max_width;
	int	max_height;

	grid->col = col;
	grid->row = row;
	max_width = (WIDTH * 0.80) / col;
	max_height = (HEIGHT * 0.80) / row;
	if (max_width > max_height)
		grid->box_length = max_width;
	else
		grid->box_length = max_height;
	grid->tmp_grid = grid_alloc(row, col);
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
