/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4rotation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:26:59 by telee             #+#    #+#             */
/*   Updated: 2022/06/02 13:26:59 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix	rotate_x(t_point *coor, int degree)
{
	const float		rad = (degree) * (60.0 / 180.0);
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
	coortmp.y = coor->y * tmp.e + (coor->z * tmp.h);
	coortmp.z = -(coor->y) * tmp.h + (coor->z * tmp.i);
	coor->y = coortmp.y;
	coor->z = coortmp.z;
	return (tmp);
}

t_matrix	rotate_y(t_point *coor, int degree)
{
	const float		rad = (degree) * (60.0 / 180.0);
	t_matrix		tmp;
	t_point			coortmp;

	tmp.a = cos(rad);
	tmp.b = 0;
	tmp.c = sin(rad);
	tmp.d = 0;
	tmp.e = 1;
	tmp.f = 0;
	tmp.g = -sin(rad);
	tmp.h = 0;
	tmp.i = cos(rad);
	coortmp.x = coor->x * tmp.a + (coor->z * tmp.c);
	coortmp.z = -(coor->x) * tmp.c + (coor->z * tmp.a);
	coor->x = coortmp.x;
	coor->z = coortmp.z;
	return (tmp);
}

t_matrix	rotate_z(t_point *coor, int degree)
{
	const float		rad = (degree) * (60.0 / 180.0);
	t_matrix		tmp;
	t_point			coortmp;

	tmp.a = cos(rad);
	tmp.b = -sin(rad);
	tmp.c = 0;
	tmp.d = sin(rad);
	tmp.e = cos(rad);
	tmp.f = 0;
	tmp.g = 0;
	tmp.h = 0;
	tmp.i = 1;
	coortmp.x = coor->x * tmp.a - (coor->y * tmp.d);
	coortmp.y = coor->x * tmp.d + (coor->y * tmp.a);
	coor->x = coortmp.x;
	coor->y = coortmp.y;
	return (tmp);
}

void	rotate(t_point *coor, char axis, int degree)
{
	t_matrix	matrix;
	// t_point		tmp;

	if (axis == 'x')
		matrix = rotate_x(coor, degree);
	else if (axis == 'y')
		matrix = rotate_y(coor, degree);
	else if (axis == 'z')
		matrix = rotate_z(coor, degree);
	// tmp.x = coor->x;
	// tmp.y = coor->y;
	// tmp.z = coor->z;
	// coor->x = (tmp.x * matrix.a) + (tmp.y * matrix.b) + (tmp.z * matrix.c);
	// coor->y = (tmp.x * matrix.d) + (tmp.y * matrix.e) + (tmp.z * matrix.f);
	// coor->z = (tmp.x * matrix.g) + (tmp.y * matrix.h) + (tmp.z * matrix.i);
}
