/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9rotation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:22:20 by telee             #+#    #+#             */
/*   Updated: 2022/05/28 10:22:20 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix	rotate_x(int degree)
{
	const float		rad = (degree) * (60.0 / 180.0);
	t_matrix		tmp;

	tmp.a = 1;
	tmp.b = 0;
	tmp.c = 0;
	tmp.d = 0;
	tmp.e = cos(rad);
	tmp.f = -sin(rad);
	tmp.g = 0;
	tmp.h = sin(rad);
	tmp.i = cos(rad);
	return (tmp);
}

t_matrix	rotate_y(int degree)
{
	const float		rad = (degree) * (60.0 / 180.0);
	t_matrix		tmp;

	tmp.a = cos(rad);
	tmp.b = 0;
	tmp.c = sin(rad);
	tmp.d = 0;
	tmp.e = 1;
	tmp.f = 0;
	tmp.g = -sin(rad);
	tmp.h = 0;
	tmp.i = cos(rad);
	return (tmp);
}

t_matrix	rotate_z(int degree)
{
	const float		rad = (degree) * (60.0 / 180.0);
	t_matrix		tmp;

	tmp.a = cos(rad);
	tmp.b = -sin(rad);
	tmp.c = 0;
	tmp.d = sin(rad);
	tmp.e = cos(rad);
	tmp.f = 0;
	tmp.g = 0;
	tmp.h = 0;
	tmp.i = 1;
	return (tmp);
}

void	rotate(t_point *coor, char axis, int degree)
{
	t_matrix	matrix;
	t_point		tmp;

	if (axis == 'x')
		matrix = rotate_x(degree);
	else if (axis == 'y')
		matrix = rotate_y(degree);
	else if (axis == 'z')
		matrix = rotate_z(degree);
	tmp.x = coor->x;
	tmp.y = coor->y;
	tmp.z = coor->z;
	coor->x = (tmp.x * matrix.a) + (tmp.y * matrix.b) + (tmp.z * matrix.c);
	coor->y = (tmp.x * matrix.d) + (tmp.y * matrix.e) + (tmp.z * matrix.f);
	coor->z = (tmp.x * matrix.g) + (tmp.y * matrix.h) + (tmp.z * matrix.i);
}
