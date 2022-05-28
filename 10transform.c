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

#include "fdf.h"

void	apply_zoom(t_point *coor, float zoom)
{
	if (zoom < 0)
		return ;
	coor->x *= zoom;
	coor->y *= zoom;
	coor->z *= zoom;
}

void	apply_translate(t_point *coor, t_trans trans)
{
	coor->x += trans.x;
	coor->y += trans.y;
}

void	apply_center(t_point *coor)
{
	coor->x = coor->x + WIDTH / 2;
	coor->y = (HEIGHT / 2) - coor->y;
}

void	apply_transformation(t_grid *grid, t_transform *tform)
{
	int	i;
	int	j;

	i = -1;
	while (++i < grid->row)
	{
		j = -1;
		while (++j < grid->col)
		{
			apply_rotate(&grid->tmp_grid[i][j], 'x', tform->rotate.x);
			apply_rotate(&grid->tmp_grid[i][j], 'y', tform->rotate.y);
			apply_rotate(&grid->tmp_grid[i][j], 'z', tform->rotate.z);
			if (tform->projection == 1)
				apply_zoom(&grid->tmp_grid[i][j], tform->zoom);
			if (tform->projection == 1)
				apply_iso(&grid->tmp_grid[i][j], tform->iso_radian_const);
			else if (tform->projection == 2)
				apply_perspective(&grid->tmp_grid[i][j], tform->z0_const);
			if (tform->projection == 2)
				apply_zoom(&grid->tmp_grid[i][j], tform->zoom);
			apply_translate(&grid->tmp_grid[i][j], tform->transform);
			apply_center(&grid->tmp_grid[i][j]);
		}
	}
}
