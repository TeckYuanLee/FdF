/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3transform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:26:49 by telee             #+#    #+#             */
/*   Updated: 2022/06/02 13:26:49 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(t_point *coor)
{
	t_point	prev;

	prev.x = coor->x;
	prev.y = coor->y;
	coor->x = (prev.x - prev.y) * cos(ISO_RAD);
	coor->y = -(coor->z) + (prev.x + prev.y) * sin(ISO_RAD);
}

void	zoom(t_point *coor, float zoom)
{
	if (zoom < 0)
		return ;
	coor->x *= zoom;
	coor->y *= zoom;
	coor->z *= zoom;
}

void	center(t_point *coor)
{
	coor->x = coor->x + WIDTH / 2;
	coor->y = (HEIGHT / 2) - coor->y;
}

void	transform(t_grid *grid, t_transform *tform)
{
	int	i;
	int	j;

	i = -1;
	while (++i < grid->row)
	{
		j = -1;
		while (++j < grid->col)
		{
			rotate(&grid->grid[i][j], tform->rotate.x);
			isometric(&grid->grid[i][j]);
			zoom(&grid->grid[i][j], tform->zoom);
			center(&grid->grid[i][j]);
		}
	}
}

void	grid_put(t_grid *grid, t_data *data, t_transform *transf)
{
	transform(grid, transf);
	gridline_put(grid, data, 0x0000FF00);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
