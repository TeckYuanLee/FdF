/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10transform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:22:51 by telee             #+#    #+#             */
/*   Updated: 2022/05/28 10:22:51 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(t_point *coor, float iso_rad_const)
{
	t_point	tmp;

	//printf("(%d, %d, %d)\n", coor->x, coor->y, coor->z);
	tmp.x = coor->x;
	tmp.y = coor->y;
	coor->x = (tmp.x - tmp.y) * cos(iso_rad_const);
	coor->y = -(coor->z) + (tmp.x + tmp.y) * sin(iso_rad_const);
	coor->z = coor->z;
	//printf("(%d, %d, %d)\n\n", coor->x, coor->y, coor->z);
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
			rotate(&grid->tmp_grid[i][j], 'x', tform->rotate.x);
			rotate(&grid->tmp_grid[i][j], 'y', tform->rotate.y);
			rotate(&grid->tmp_grid[i][j], 'z', tform->rotate.z);
			isometric(&grid->tmp_grid[i][j], tform->iso_radian_const);
			zoom(&grid->tmp_grid[i][j], tform->zoom);
			center(&grid->tmp_grid[i][j]);
		}
	}
}
