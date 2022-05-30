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
	transform(grid, transf);
	gridline_put(grid, data, 0x0000FF00);
	mlx_put_image_to_window(data->mlx,
		data->win, data->img, 0, 0);
}

int	exit_win(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		exit(0);
		return (0);
	}
	return (-1);
}
