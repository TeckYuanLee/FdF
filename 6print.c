/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6print.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:26 by telee             #+#    #+#             */
/*   Updated: 2022/05/27 19:42:26 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	blank_put(t_data *data)
{
	clean_image(data);
	mlx_put_image_to_window(data->mlx,
		data->win, data->img, 0, 0);
}

void	grid_put(t_grid *grid, t_data *data, t_transform *transf)
{
	clean_image(data);
	grid_dup(grid);
	apply_transformation(grid, transf);
	gridline_put(grid, data, 0x0000FF00);
	mlx_put_image_to_window(data->mlx,
		data->win, data->img, 0, 0);
}
