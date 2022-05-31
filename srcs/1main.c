/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:20 by telee             #+#    #+#             */
/*   Updated: 2022/05/27 19:42:20 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_window(t_data *data, char *title)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int	init_grid(t_grid *grid, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File error.\n", 2);
		return (-1);
	}
	if (grid_build(fd, grid) == -1)
	{
		ft_putstr_fd("Map error.\n", 2);
		return (-1);
	}
	return (0);
}

void	init_transform(t_transform *transf)
{
	transf->rotate.x = 9;
	transf->rotate.y = 10;
	transf->rotate.z = 90;
	transf->zoom = 0.5;
	transf->iso_radian_const = 10;//(30 / 180.0) * 60.0;
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_grid		grid;
	t_transform	transf;

	if (argc == 2)
	{
		if (init_grid(&grid, argv[1]) == -1)
			return (2);
		init_window(&data, argv[1]);
		init_transform(&transf);
		grid_put(&grid, &data, &transf);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_hook(data.win, 17, 1L << 1, exit_win, &data);
		free_grid(grid.grid, grid.row);
		free_grid(grid.tmp_grid, grid.row);
	}
	else
	{
		ft_putstr_fd("Please insert map\n", 2);
		return (1);
	}
	mlx_loop(data.mlx);
	return (0);
}
