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

void	exit_hook(t_data *data)
{
	free_grid(data->grid.grid, data->grid.row);
	free_grid(data->grid.tmp_grid, data->grid.row);
	mlx_destroy_image(data->win.mlx, data->img.img);
	mlx_destroy_window(data->win.mlx, data->win.window);
	mlx_destroy_display(data->win.mlx);
	// important to free this once more
	free(data->win.mlx);
	exit(0);
}


void	key_hook2(int keycode, t_data *data)
{
	if (keycode == 'h')
		data->tform.zoom += 0.1;
	else if (keycode == 'u')
		data->tform.zoom -= 0.1;
	else if (keycode == 'w')
		data->tform.trans.y += 10;
	else if (keycode == 's')
		data->tform.trans.y -= 10;
	else if (keycode == 'a')
		data->tform.trans.x -= 10;
	else if (keycode == 'd')
		data->tform.trans.x += 10;
	else if (keycode == 'q')
		switch_projection(&data->tform.projection);
}


int	key_hook(int keycode, t_data *data)
{
	if (keycode == 'j')
		data->tform.rot.x += 5;
	else if (keycode == 'i')
		data->tform.rot.x += -5;
	else if (keycode == 'k')
		data->tform.rot.y += 5;
	else if (keycode == 'o')
		data->tform.rot.y += -5;
	else if (keycode == 'l')
		data->tform.rot.z += 5;
	else if (keycode == 'p')
		data->tform.rot.z += -5;
	// keycode 65307 represents 'Esc'
	if (keycode == 65307)
		exit_hook(data);
	key_hook2(keycode, data);
	if (data->tform.zoom > 0.0)
		output_grid(data);
	else
		output_blank(data);
	return (0);
}
