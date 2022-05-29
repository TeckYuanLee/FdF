/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8projection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:22:11 by telee             #+#    #+#             */
/*   Updated: 2022/05/28 10:22:11 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perspective(t_point *coor, double Z0)
{
	coor->x = (coor->x * Z0) / (Z0 + coor->z);
	coor->y = (coor->y * Z0) / (Z0 + coor->z);
}

void	apply_iso(t_point *coor, float iso_rad_const)
{
	t_point	tmp;

	tmp.x = coor->x;
	tmp.y = coor->y;
	coor->x = (tmp.x - tmp.y) * cos(iso_rad_const);
	coor->y = -(coor->z) + (tmp.x + tmp.y) * sin(iso_rad_const);
	coor->z = coor->z;
}

void	switch_projection(int *projection)
{
	if (*projection == 1)
		*projection = 2;
	else
		*projection = 1;
}
