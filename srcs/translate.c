/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:09:54 by telee             #+#    #+#             */
/*   Updated: 2022/06/02 21:09:54 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate(t_point *coor, int degree)
{
	const float		rad = (degree);
	t_matrix		tmp;
	t_point			coortmp;

	tmp.a = 1;
	tmp.b = 0;
	tmp.c = 0;
	tmp.d = 0;
	tmp.e = cos(rad);
	tmp.f = -sin(rad);
	tmp.g = 0;
	tmp.h = sin(rad);
	tmp.i = cos(rad);
	coortmp.x = coor->x;
	coortmp.y = coor->y;
	coor->x = (coortmp.x * tmp.e) - (coortmp.y * tmp.h);
	coor->y = (coortmp.y * tmp.e) + (coortmp.x * tmp.h);
}

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

void	translate(t_grid *grid)
{
	int	i;
	int	j;

	i = -1;
	while (++i < grid->row)
	{
		j = -1;
		while (++j < grid->col)
		{
			rotate(&grid->grid[i][j], DEGREE);
			isometric(&grid->grid[i][j]);
			zoom(&grid->grid[i][j], ZOOM);
			center(&grid->grid[i][j]);
		}
	}
}
