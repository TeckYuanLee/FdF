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
